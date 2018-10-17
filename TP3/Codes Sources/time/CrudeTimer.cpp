#include "CrudeTimer.h"
//#include "../stdafx.h"

CrudeTimer* CrudeTimer::Instance()
{
  static CrudeTimer instance;

  return &instance;
}