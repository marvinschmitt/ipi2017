#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdint>

class Image
{
public:
  typedef uint16_t PixelType;

private:
  int width_;
  int height_;
  std::vector<PixelType> data_;

public:
  // Standardkonstruktor: initialisiere Bild mit Groesse (0,0)
  Image()
    : width_(0), height_(0)
  {
    this->data_.resize(0);
  }

  // Konstruktor: initialisiere Bild mit Groesse (width, height)
  // Alle Pixel sollen danach den Wert '0' haben.
  Image(unsigned int width, unsigned int height)
    : width_(width), height_(height)
  {
    data_.resize(width * height, 0);      // data_ auf Größe width*height setzen und mit Nullen füllen.
  }

  // Breite abfragen
  unsigned int width() const {
    return this->width_;
  }

  // Hoehe abfragen
  unsigned int height() const {
    return this->height_;
  }

  // Gesamtzahl der Pixel abfragen
  unsigned int size() const {
    return this->width_ * this->height_;
  }

  // Groesse der Bildes aendern. Welche Methode der Klasse vector
  // ist hier sinnvoll?
  void resize(unsigned int new_width, unsigned int new_height) {
    this->data_.resize(new_width * new_height);
  }

  // lesender Zugriff auf des Pixel an Position (x,y)
  PixelType operator()(int x, int y) const {
      return this->data_.at(y * this->width_ + x);
  }

  // Lese/Schreib-Zugriff auf des Pixel an Position (x,y)
  PixelType & operator()(int x, int y) {
      return this->data_.at(y * this->width_ + x);
  }
};


// Gib 'true' zurueck, wenn die gegebenen Bilder gleich sind.
// Dies ist der Fall, wenn die Bildgroessen uebereinstimmen und
// alle Pixel die gleichen Werte haben.
// Diese Funktion ist nuetzlich zum Testen der Bildklasse.
bool operator==(Image const & im0, Image const & im1) {
  if (im0.size() != im1.size()) return false;     // Wenn Größe ungleich --> return false;
  else                                            // Wenn Größe gleich, geht es weiter.
  {                                               // Für jeden Pixel Gleichheit prüfen:
    for (unsigned int y = 0; y < im0.height(); y++)
    {
      for (unsigned int x = 0; x < im0.width(); x++)
      {
        if (im0(x, y) != im1(x, y)) return false; // Wenn ein Pixelpaar ungleich ist --> return false;
      }
    }
  return true;                                    // Hier kommt man nur hin, wenn alle Pixel gleich sind und die Bilder gleich groß.
  }
}

// Wandle die Pixelwerte zeilenweise in einen String.
// Fuer ein Bild der Groesse 4x3, das die Pixelwerte 0 und 1
// in Schachbrett-Anordnung enthaelt, soll z.B. der String
//         "0 1 0 1\n1 0 1 0\n0 1 0 1\n"
// zurueckgegeben werden (Pixelwerte sind durch Leerzeichen
// getrennt, am Ende jeder Zeile steht ein Enter-Zeichen '\n').
// Finden Sie heraus, welche Methode der C++-Standardbibliothek
// eine Variable vom Typ int in einen String umwandelt.
std::string to_string(Image const & im) {
  std::string res;
  for (unsigned int y = 0; y < im.height(); y++)
  {
    for (unsigned int x = 0; x < im.width(); x++)
    {
      res += std::to_string(im(x, y));
      res += " ";
    }
  res += "\n";
  }


  return res;
}

// Gib das Bild im PGM-Format in das File 'filename' aus.
//
// Die Bilddatei kann mit allen Bildbetrachtern angezeigt
// werden, die das PGM-Format unterstuetzen (unter Windows
// z.B. 'IrfanView', unter Linux z.B. 'display' aus der
// imagemagick-Installation, ueberall 'gimp').
//
// Da das PGM-Format ein Textformat ist, kann man es zum
// Debuggen auch im Editor oeffnen und ueberpruefen.
void writePGM(Image const & img, std::string const & filename) {
  // Filestream erzeugen
  std::ofstream pgm(filename, std::ios::binary);

  // Fehlermeldung, wenn sich das File nicht oeffnen laesst.
  if (!pgm) {
    throw std::runtime_error("writePGM(): cannot open file '" + filename + "'.");
  }

  // Headerinformationen schreiben
  int max_pixelvalue = 255;
  pgm << "P2\n"
      << img.width() << " " << img.height() << "\n"
      << max_pixelvalue << "\n";

  // Bilddaten schreiben (verwendet Ihre Funktion 'to_string').
  pgm << to_string(img);
}

// Gib 'true' zurueck, wenn das File 'filename' das PGM-Format hat.
bool checkPGM(std::string const & filename) {
  std::ifstream pgm(filename);
  std::string line;

  // Teste, ob das File geoeffnet werden kann und
  // mindestens eine Zeile hat.
  if (!std::getline(pgm, line)) {
    return false;
  }

  // Teste, dass die erste Zeile der String "P2" ist.
  return line == "P2";
}

// Lese das File 'filename' (im PGM-Format) ein und gib das resultierende
// Bild zurueck.
Image readPGM(std::string const & filename) {
  // Fehlermeldung, wenn sich das File nicht oeffnen laesst
  // oder kein PGM-File ist.
  if (!checkPGM(filename)) {
    throw std::runtime_error("readPGM(): File '" + filename + "' is not PGM.");
  }

  // Filestream erzeugen
  std::ifstream pgm(filename);
  std::string line;

  // erste Zeile einlesen (enthaelt den String "P2")
  std::getline(pgm, line);

  // eventuelle Kommentarzeilen ueberspringen
  while (pgm.peek() == '#') {
    std::getline(pgm, line);
  }

  // Breite und Hoehe einlesen
  int width, height;
  pgm >> width >> height;

  // maximalen Grauwert einlesen und Fehlermeldung ausgeben, falls zu gross
  int max_value;
  pgm >> max_value;
  if (max_value > 255) {
    throw std::runtime_error("readPGM(): max value must be <= 255.");
  }

  // Ergebnisbild der gewuenschten Groesse erzeugen
  Image res(width, height);

  // Pixeldaten in einer zweifach geschachtelten Schleife ueber
  // die Zeilen und Spalten einlesen.

  for (unsigned int y = 0; y < res.height(); y++)
  {
    for (unsigned int x = 0; x < res.width(); x++)
    {
      pgm >> res(x, y);
    }
  }

  return res;
}



Image chessboard(unsigned int width, unsigned int height, unsigned int square_size)
{
  Image board(width, height);
  bool white_current, white_last_row = false;     

  for (unsigned int y = 0; y < height; y++)
  {
    if (y % square_size == 0) white_last_row = !white_last_row;         // Alle zwei Reihen Anfangsfarbe der Reihe tauschen.
    white_current = white_last_row;
    for (unsigned int x = 0; x < width; x++)
    {
      if ( x % square_size == 0) white_current = !white_current;      //alle zwei Felder Farbe tauschen.
      board(x, y) = 255*white_current;
    }
  }

  return board;
}


Image invert_image(Image const& image)
{
  Image inverted_image(image.width(), image.height());    // create image of same size
  for (unsigned int y = 0; y < image.height(); y++)
  {
    for (unsigned int x = 0; x < image.width(); x++)
    {
      inverted_image(x, y) = 255 - image(x, y);
    }
  }
  return inverted_image;
}

//  NEW METHODS FOR KALEIDOSCOPE

Image mirror_x (Image const& image)
{
  unsigned int width = image.width(), height = image.height();    // width and height of source image
  Image new_image(width*2, height);
  for (unsigned int y = 0; y < height; y++)
  {
    for (unsigned int x = 0; x < width; x++)
    {
      new_image(x, y) = image(x, y);
      new_image(width-1 + x, y) = image(width-1 - x, y);
    }
  }
  return new_image;
}

Image mirror_y (Image const& image)
{
  unsigned int width = image.width(), height = image.height();    // width and height of source image
  Image new_image(width, height*2);
  for (unsigned int y = 0; y < height; y++)
  {
    for (unsigned int x = 0; x < width; x++)
    {
      new_image(x, y) = image(x, y);
      new_image(x, height-1 + y) = image(x, height-1 - y);
    }
  }
  return new_image;
}

Image kaleidoscope4 (Image const& image)
{
  return mirror_y(mirror_x(image));
}

Image kaleidoscope8 (Image const& image)
{
  Image new_image = image;

  for (unsigned int y = 0; y < image.height(); y++)
  {
    for (unsigned int x = 0; x < image.width(); x++)
    {
      if (x>y) new_image(x, y) = image (y, x);
    }
  }
  new_image = kaleidoscope4(new_image);
  return new_image;
}


#endif // IMAGE_H

