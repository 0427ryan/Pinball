#include "Shape.h"
#include <vector.h>

class Polygon:public Shape{
  vector<MyVector> coords;
  
 public:
    Rectangle(vector<MyVector> coords){
      this->coords = coords;
    };
    bool isBump(Ball *b) override;
    void doBump(Ball *b) override;
    vector<MyVector>* getCoords(){return &coords};
}
