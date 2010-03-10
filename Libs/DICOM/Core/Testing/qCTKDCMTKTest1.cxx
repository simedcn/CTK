#include <QTextStream>

#include "qCTKDCMTK.h"

#include <iostream>
#include <cstdlib>

int qCTKDCMTKTest1(int argc, char** argv) {
 
  QTextStream out(stdout);
  qCTKDCMTK myCTK;
  if ( myCTK.openDatabase( argv[1]) )
    {
    out << "open db success\n";
    myCTK.initializeDatabase();
    }
  else
    { 
    out << "ERROR: " ;
    out << myCTK.GetLastError();
    }
  return EXIT_SUCCESS;
}

