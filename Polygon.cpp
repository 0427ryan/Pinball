#include "Polygon.h"

bool Polygon::isBump(Ball *b){
  for(int i = 0 ; i < coords.size() ; i++){
    MyVector temp1 = coords[(i + 1) % coords.size()] - coords[i];
    MyVector temp2 = ball->getLocation() - coords[i];
    if(temp1.x * temp2.y - temp1.y * temp2.x > 0){
      return false;
    }
  }
  return true;
}
