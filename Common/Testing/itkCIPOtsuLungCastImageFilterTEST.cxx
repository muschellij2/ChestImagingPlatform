#include "cipConventions.h"
#include "itkCIPOtsuLungCastImageFilter.h"
#include "itkImageRegionIterator.h"

int main( int argc, char* argv[] )
{
  typedef itk::CIPOtsuLungCastImageFilter< cip::CTType > CIPOtsuCastType;
  typedef itk::ImageRegionIterator< cip::LabelMapType >  IteratorType;

  // Read the CT image
  std::cout << "Reading CT..." << std::endl;
  cip::CTReaderType::Pointer reader = cip::CTReaderType::New();
    reader->SetFileName( argv[1] );
  try
    {
    reader->Update();
    }
  catch ( itk::ExceptionObject &excp )
    {
    std::cerr << "Exception caught reading test image:";
    std::cerr << excp << std::endl;
    }

  std::cout << "Getting cast..." << std::endl;
  CIPOtsuCastType::Pointer segmenter = CIPOtsuCastType::New();
    segmenter->SetInput( reader->GetOutput() );
    segmenter->Update();

  // Read the reference label mape
  std::cout << "Reading reference..." << std::endl;
  cip::LabelMapReaderType::Pointer referenceReader = cip::LabelMapReaderType::New();
    referenceReader->SetFileName( argv[2] );
  try
    {
    referenceReader->Update();
    }
  catch ( itk::ExceptionObject &excp )
    {
    std::cerr << "Exception caught reading reference label map:";
    std::cerr << excp << std::endl;
    }

  IteratorType segIt( segmenter->GetOutput(), segmenter->GetOutput()->GetBufferedRegion() );
  IteratorType refIt( referenceReader->GetOutput(), referenceReader->GetOutput()->GetBufferedRegion() );

  unsigned int refCount = 0;
  unsigned int segCount = 0;
  unsigned int intCount = 0;

  segIt.GoToBegin();
  refIt.GoToBegin();
  while ( !refIt.IsAtEnd() )
    {
      if ( refIt.Get() !=0 )
  	{
  	  refCount++;
  	}
      if ( segIt.Get() != 0 )
  	{
  	  segCount++;
  	}
      if ( refIt.Get() !=0 && segIt.Get() != 0 )
  	{
  	  intCount++;
  	}

      ++segIt;
      ++refIt;
    }

  double dice = 2.0*double(intCount)/double(refCount + segCount);

  if ( dice == 1.0 )
    {
      std::cout << "PASSED" << std::endl;
      return 0;
    }

  return 1;
}
