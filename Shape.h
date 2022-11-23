#include "MyVector.h"
#include "Ball.h"

class Shape{
 public:
  virtual bool isBump(Ball b);
  virtual void doBump(Ball b);
}
