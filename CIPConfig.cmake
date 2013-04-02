#
# See UseCIP.cmake for explanation how to use CIP code
# from an external project.
#

MESSAGE( STATUS "Configuring CIP" )

#---------------------------------------------------------------------
# Set all necessary include directories for CIP
SET( CIP_INCLUDE_DIRECTORIES "/Users/jross/Downloads/cip/trunk/Common;/Users/jross/Downloads/cip/trunk/Utilities/ITK;/Users/jross/Downloads/cip/trunk/Utilities/VTK" )

# Set the directory that contains the CIP libraries,
# such as CIP-Common.
SET( CIP_LIBRARY_OUTPUT_PATH "/Users/jross/Downloads/cip/trunk/bin" )

# Read in the library dependencies
SET( CIP_LIBRARY_DEPENDS_FILE "" )

#---------------------------------------------------------------------
# Set some variables that the user might want to use
SET( CIP_LIBRARIES CIPCommon;CIPUtilities )
SET( CIP_INSTALL_DIR "/usr/local/bin" )
SET( CIP_MACRO_DEFINITIONS "" )
SET( CIP_USE_FILE "/Users/jross/Downloads/cip/trunk/UseFile.cmake" )

