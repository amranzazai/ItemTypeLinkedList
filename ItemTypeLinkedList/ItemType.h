/*
 * ItemType.h
 *
 *  Created on: Feb 15, 2021
 *      Author: amranzazai
 */
// The following declarations and definitions go into file
// ItemType.h.

#include <fstream>
#include <string>
const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType
{
public:
  ItemType();
  RelationType ComparedTo(ItemType) const;
  void Print(std::ostream&) const;
  void Initialize(int number);
private:
  int value;
};
