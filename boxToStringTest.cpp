#include "shapes.h"
#include "shapeFuncs.h"
#include "tddFuncs.h"




int main() {

  struct Box b1,b2;
  initBox(&b1, 0.0, 1.0, 2.0, 3.0);
  assertEquals("ul=(0,1),w=2,h=3", boxToString(b1), "boxToString(b1)");

  initBox(&b2, 3.3333333, 6.6666667, 1.2345679, 2.7182818); 
  // 1/3, 2/3, 100/81, euler's number
  assertEquals("ul=(3.3,6.7),w=1.2,h=2.7", boxToString(b2,2), "boxToString(b2,2)");
  assertEquals("ul=(3.33,6.67),w=1.23,h=2.72", boxToString(b2), "boxToString(b2)");
  assertEquals("ul=(3.333,6.667),w=1.235,h=2.718", boxToString(b2,4), "boxToString(b2,4)");
  assertEquals("ul=(3.3333,6.6667),w=1.2346,h=2.7183", boxToString(b2,5), "boxToString(b2,5)");

  return 0;
}
