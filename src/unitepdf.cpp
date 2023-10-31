#include <PdfOps.h>

#include <stdio.h>

int main( int argc, char* argv[] )
{
  std::vector<std::string> inputFiles;
  for ( int i=1; i < argc-1; ++i)
  {
    printf("%s\n", argv[i]);
    inputFiles.push_back( argv[i] );
  }

  PdfOps::UniteFiles( inputFiles, argv[argc-1] );
}
