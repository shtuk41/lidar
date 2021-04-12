#include <iostream>
#include <fstream>
#include <vector>

#pragma pack(push, r1, 1)
struct lasheader
{
    char fileSignature[4]; 
    unsigned short fileSourceId; 
    unsigned short globalEncoding;
    unsigned int projectIDGuidData1;//unsigned long
    unsigned short projectIDGuidData2;
    unsigned short projectIDGuidData3;
    unsigned char projectIDGuidData4[8];
    unsigned char versionMajor;
    unsigned char versionMinor;
    char systemIdentifier[32];
    char generatingSoftware[32];
    unsigned short fileCreationDayOfYear;
    unsigned short fileCreationYear;
    unsigned short headerSize;
    unsigned int offsetToPointData;
    unsigned int numberOfVariableLengthRecords;
    unsigned char pointDataRecordFormat;
    unsigned short pointDataRecordLength;
    unsigned int legacyNumberOfPointRecords;
    unsigned int legacyNumberOfPointsByReturn[5];
    double xScaleFactor;
    double yScaleFactor;
    double zScaleFactor;
    double xOffset;
    double yOffset;
    double zOffset;
    double maxX;
    double minX;
    double maxY;
    double minY;
    double maxZ;
    double minZ;
    unsigned long long startOfWaveformDataPacketRecord;
    unsigned long long startOfFirstExtendedVariableLengthRecord;
    unsigned int numberOfExtendedVariableLengthRecords;
    unsigned long long numberOfPointRecords;
    unsigned long long numberOfPointsByReturn[15];      
};

struct PointDatarecordFormat_1
{
    int x;
    int y;
    int z;
    unsigned short intensity;
    char flags;     //0-2 return number
                    //3-5 number of returns (given pulse)
                    //bit 6 - scan direction flag
                    //bit 7 - edge of flight line
    unsigned char classification;
    char scanAngleRank;
    unsigned char userData;
    unsigned short pointSourceId;
    double gpsTime;
};


#pragma pack(pop, r1)

void printRecord(const PointDatarecordFormat_1 &record)
{
    std::cout << "x: " << record.x << std::endl;
    std::cout << "y: " << record.y << std::endl;
    std::cout << "z: " << record.z << std::endl;
    std::cout << "intensity: " << record.intensity << std::endl;
}

void printLasHeader(const lasheader &lh)
{
    std::cout << "File signature: ";
    
    for (int ii = 0; ii < 4; ii++)
        std::cout << lh.fileSignature[ii];
    
    std::cout << std::endl;
    std::cout << "File source ID: " << lh.fileSourceId << std::endl;
    std::cout << "Global encoding " << lh.globalEncoding << std::endl;
    std::cout << "Project ID Guid Data 1: " << lh.projectIDGuidData1 << std::endl;
    std::cout << "Project ID Guid Data 2: " << lh.projectIDGuidData2 << std::endl;
    std::cout << "Project ID Guid Data 3: " << lh.projectIDGuidData3 << std::endl;
    std::cout << "Project ID Guid Data 4: ";
    
    for (int ii = 0; ii < 8; ii++)
    {
        std::cout << (int)lh.projectIDGuidData4[ii];
    }
    
    std::cout << std::endl;
    
    std::cout << "Version major: " << (int)lh.versionMajor << std::endl;
    std::cout << "Version minor: " << (int)lh.versionMinor << std::endl;

    std::cout << "System identifier: ";
    
    for (int ii = 0; ii < 32; ii++)
    {
        std::cout << lh.systemIdentifier[ii];
    }
    
    std::cout << std::endl;
    
    std::cout << "Generating software: ";
    
    for (int ii = 0; ii < 32; ii++)
    {
        std::cout << lh.generatingSoftware[ii];
    }
    
     std::cout << std::endl;
   
    std::cout << "File creation day of year: " << lh.fileCreationDayOfYear << std::endl;
    std::cout << "File creation year: " << lh.fileCreationYear << std::endl;
    std::cout << "Header size: " << lh.headerSize << std::endl;
    std::cout << "Offset to point data: " << lh.offsetToPointData << std::endl;
    std::cout << "Number of variable length records: " << lh.numberOfVariableLengthRecords << std::endl;
    std::cout << "Point data record format: " << (int)lh.pointDataRecordFormat << std::endl;
    std::cout << "Point data record length: " << lh.pointDataRecordLength << std::endl;
    std::cout << "Legacy number of points records: " << lh.legacyNumberOfPointRecords << std::endl;

    std::cout << "Legacy number of points by return: ";
    
    for (int ii = 0; ii < 5; ii++)
    {
        std::cout << lh.legacyNumberOfPointsByReturn[ii];
    }
    
    std::cout << std::endl;
    
    std::cout << "X scale factor: " << lh.xScaleFactor << std::endl;
    std::cout << "Y scale factor: " << lh.yScaleFactor << std::endl;
    std::cout << "Z scale factor: " << lh.zScaleFactor << std::endl;
    
    std::cout << "X offset: " << lh.xOffset << std::endl;
    std::cout << "Y offset: " << lh.yOffset << std::endl;
    std::cout << "Z offset: " << lh.zOffset << std::endl;

    std::cout << "max X: " << lh.maxX << std::endl;
    std::cout << "min X: " << lh.minX << std::endl;
    std::cout << "max Y: " << lh.maxY << std::endl;
    std::cout << "min Y: " << lh.minY << std::endl;
    std::cout << "max Z: " << lh.maxZ << std::endl;
    std::cout << "min Z: " << lh.minZ << std::endl;
    
    std::cout << "startOfWaveformDataPacketRecord: " << lh.startOfWaveformDataPacketRecord << std::endl;
    std::cout << "startOfFirstExtendedVariableLengthRecord: " << lh.startOfFirstExtendedVariableLengthRecord << std::endl;
    std::cout << "numberOfExtendedVariableLengthRecords: " << lh.numberOfExtendedVariableLengthRecords << std::endl;
    std::cout << "numberOfPointRecords: " << lh.numberOfPointRecords << std::endl;
    
    std::cout << "numberOfPointsByReturn: ";
    
    for (int ii = 0; ii < 15; ii++)
    {
        std::cout << lh.numberOfPointsByReturn[ii];
    }
    
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::cout << "starting parselas" << std::endl;
    
    std::ifstream lasfile("//home//aleksander//Downloads//first.las", std::ios::in | std::ios::binary);
    
    std::cout << sizeof(unsigned short) << std::endl;
    std::cout << sizeof(unsigned long) << std::endl;
    std::cout << sizeof(unsigned int) << std::endl;
    std::cout << sizeof(unsigned char) << std::endl;
    std::cout << sizeof(unsigned long long) << std::endl;
    std::cout << sizeof(long) << std::endl;
    
    
    
    if (lasfile.good())
    {
        std::cout << "file exists" << std::endl;
        
        lasheader header;
        
        lasfile.read((char*)&header, sizeof(header));
        
        printLasHeader(header);
        
        /*std::vector<PointDatarecordFormat_1> *data = new std::vector<PointDatarecordFormat_1>();
        
        lasfile.seekg(header.offsetToPointData);
        
        for (unsigned int ii = 0; ii < header.legacyNumberOfPointRecords; ii++)
        {
            PointDatarecordFormat_1 d;
            
            lasfile.read((char*)&d, sizeof(PointDatarecordFormat_1));
            
            data->push_back(d);
        }
        
        
        unsigned int count = 0;
        for (std::vector<PointDatarecordFormat_1>::iterator it = data->begin(); it != (*data).end(); ++it)
        {
            printRecord(*it);
            
            std::cout << "count: " <<  count << std::endl;
            
            count++;
            
        }
        
        
        delete data;*/
    }
    else
    {
        
        std::cout << "cannot find file" << std::endl;
    }
    
    
    return 0;
}