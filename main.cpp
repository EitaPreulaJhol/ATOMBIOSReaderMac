#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdint>

// Define 1 byte como o alinhamento para as estruturas:
#pragma pack(push, 1)

// Define algumas estruturas básicas encontradas dentro da BIOS ATOM:
struct _ATOM_COMMON_TABLE_HEADER {
    uint16_t usStructureSize;
    uint8_t  ucTableFormatRevision;
    uint8_t  ucTableContentRevision;
};

// Define a estrutura do cabeçalho principal da BIOS ATOM:
struct _ATOM_ROM_HEADER {
    _ATOM_COMMON_TABLE_HEADER sHeader;
    uint8_t  uaFirmWareSignature[4]; // Aqui é onde a assinatura "ATOM" é armazenada
    uint16_t usBiosRuntimeSegmentAddress;
    uint16_t usProtectedModeInfoOffset;
    uint16_t usConfigFilenameOffset;
    uint16_t usCRC_BlockOffset;
    uint16_t usBIOS_BootupMessageOffset;
    uint16_t usInt10Offset;
    uint16_t usPciBusDevInitCode;
    uint16_t usIoBaseAddress;
    uint16_t usSubsystemVendorID;
    uint16_t usSubsystemID;
    uint16_t usPCI_InfoOffset;
    uint16_t usMasterCommandTableOffset;
    uint16_t usMasterDataTableOffset;
    uint8_t  ucExtendedFunctionCode;
    uint8_t  ucReserved;
};

// Estruturas dos comandos dentro da BIOS ATOM:
struct _ATOM_MASTER_LIST_OF_COMMAND_TABLES {
    uint16_t ASIC_Init;
    uint16_t GetDisplaySurfaceSize;
    uint16_t ASIC_RegistersInit;
    uint16_t VRAM_BlockVenderDetection;
    uint16_t DIGxEncoderControl;
    uint16_t MemoryControllerInit;
    uint16_t EnableCRTCMemReq;
    uint16_t MemoryParamAdjust;
    uint16_t DVOEncoderControl;
    uint16_t GPIOPinControl;
    uint16_t SetEngineClock;
    uint16_t SetMemoryClock;
    uint16_t SetPixelClock;
    uint16_t EnableDispPowerGating;
    uint16_t ResetMemoryDLL;
    uint16_t ResetMemoryDevice;
    uint16_t MemoryPLLInit;
    uint16_t AdjustDisplayPll;
    uint16_t AdjustMemoryController;
    uint16_t EnableASIC_StaticPwrMgt;
    uint16_t SetUniphyInstance;
    uint16_t DAC_LoadDetection;
    uint16_t LVTMAEncoderControl;
    uint16_t HW_Misc_Operation;
    uint16_t DAC1EncoderControl;
    uint16_t DAC2EncoderControl;
    uint16_t DVOOutputControl;
    uint16_t CV1OutputControl;
    uint16_t GetConditionalGoldenSetting;
    uint16_t TVEncoderControl;
    uint16_t PatchMCSetting;
    uint16_t MC_SEQ_Control;
    uint16_t Gfx_Harvesting;
    uint16_t EnableScaler;
    uint16_t BlankCRTC;
    uint16_t EnableCRTC;
    uint16_t GetPixelClock;
    uint16_t EnableVGA_Render;
    uint16_t GetSCLKOverMCLKRatio;
    uint16_t SetCRTC_Timing;
    uint16_t SetCRTC_OverScan;
    uint16_t SetCRTC_Replication;
    uint16_t SelectCRTC_Source;
    uint16_t EnableGraphSurfaces;
    uint16_t UpdateCRTC_DoubleBufferRegisters;
    uint16_t LUT_AutoFill;
    uint16_t EnableHW_IconCursor;
    uint16_t GetMemoryClock;
    uint16_t GetEngineClock;
    uint16_t SetCRTC_UsingDTDTiming;
    uint16_t ExternalEncoderControl;
    uint16_t LVTMAOutputControl;
    uint16_t VRAM_BlockDetectionByStrap;
    uint16_t MemoryCleanUp;
    uint16_t ProcessI2cChannelTransaction;
    uint16_t WriteOneByteToHWAssistedI2C;
    uint16_t ReadHWAssistedI2CStatus;
    uint16_t SpeedFanControl;
    uint16_t PowerConnectorDetection;
    uint16_t MC_Synchronization;
    uint16_t ComputeMemoryEnginePLL;
    uint16_t MemoryRefreshConversion;
    uint16_t VRAM_GetCurrentInfoBlock;
    uint16_t DynamicMemorySettings;
    uint16_t MemoryTraining;
    uint16_t EnableSpreadSpectrumOnPPLL;
    uint16_t TMDSAOutputControl;
    uint16_t SetVoltage;
    uint16_t DAC1OutputControl;
    uint16_t DAC2OutputControl;
    uint16_t ComputeMemoryClockParam;
    uint16_t ClockSource;
    uint16_t MemoryDeviceInit;
    uint16_t GetDispObjectInfo;
    uint16_t DIG1EncoderControl;
    uint16_t DIG2EncoderControl;
    uint16_t DIG1TransmitterControl;
    uint16_t DIG2TransmitterControl;
    uint16_t ProcessAuxChannelTransaction;
    uint16_t DPEncoderService;
    uint16_t GetVoltageInfo;
};

struct _ATOM_MASTER_COMMAND_TABLE {
    _ATOM_COMMON_TABLE_HEADER sHeader;
    _ATOM_MASTER_LIST_OF_COMMAND_TABLES ListOfCommandTables;
};

// Estrutura dos dados dentro da BIOS ATOM
// Contém tabelas relacionadas a funções como PowerPlay, controle de clock, timmings de vídeo, etc.:
struct _ATOM_MASTER_LIST_OF_DATA_TABLES {
    uint16_t UtilityPipeLine;
    uint16_t MultimediaCapabilityInfo;
    uint16_t MultimediaConfigInfo;
    uint16_t StandardVESA_Timing;
    uint16_t FirmwareInfo;
    uint16_t PaletteData;
    uint16_t LCD_Info;
    uint16_t DIGTransmitterInfo;
    uint16_t AnalogTV_Info;
    uint16_t SupportedDevicesInfo;
    uint16_t GPIO_I2C_Info;
    uint16_t VRAM_UsageByFirmware;
    uint16_t GPIO_Pin_LUT;
    uint16_t VESA_ToInternalModeLUT;
    uint16_t ComponentVideoInfo;
    uint16_t PowerPlayInfo;
    uint16_t CompassionateData;
    uint16_t SaveRestoreInfo;
    uint16_t PPLL_SS_Info;
    uint16_t OemInfo;
    uint16_t XTMDS_Info;
    uint16_t MclkSS_Info;
    uint16_t Object_Header;
    uint16_t IndirectIOAccess;
    uint16_t MC_InitParameter;
    uint16_t ASIC_VDDC_Info;
    uint16_t ASIC_InternalSS_Info;
    uint16_t TV_VideoMode;
    uint16_t VRAM_Info;
    uint16_t MemoryTrainingInfo;
    uint16_t IntegratedSystemInfo;
    uint16_t ASIC_ProfilingInfo;
    uint16_t VoltageObjectInfo;
    uint16_t PowerSourceInfo;
};

struct _ATOM_MASTER_DATA_TABLE {
    _ATOM_COMMON_TABLE_HEADER sHeader;
    _ATOM_MASTER_LIST_OF_DATA_TABLES ListOfDataTables;
};

// Define o alinhamento padrão novamente.
// É só pra garantir que outras partes do código não sejam afetadas, porque usamos "#pragma pack(push, 1)" no início.
#pragma pack(pop)

// Tabela de comandos, na qual cada índice corresponde a um comando específico encontrado na BIOS ATOM:
const std::vector<std::string> INDEX_COMMAND_TABLE = {
    "ASIC_Init", "GetDisplaySurfaceSize", "ASIC_RegistersInit",
    "VRAM_BlockVenderDetection", "SetClocksRatio/DIGxEncoderControl", "MemoryControllerInit",
    "EnableCRTCMemReq", "MemoryParamAdjust", "DVOEncoderControl",
    "GPIOPinControl", "SetEngineClock", "SetMemoryClock",
    "SetPixelClock", "DynamicClockGating", "ResetMemoryDLL",
    "ResetMemoryDevice", "MemoryPLLInit", "AdjustDisplayPll",
    "AdjustMemoryController", "EnableASIC_StaticPwrMgt", "ASIC_StaticPwrMgtStatusChange/SetUniphyInstance",
    "DAC_LoadDetection", "LVTMAEncoderControl", "LCD1OutputControl",
    "DAC1EncoderControl", "DAC2EncoderControl", "DVOOutputControl",
    "CV1OutputControl", "GetConditionalGoldenSetting/SetCRTC_DPM_State", "TVEncoderControl",
    "TMDSAEncoderControl", "LVDSEncoderControl", "TV1OutputControl",
    "EnableScaler", "BlankCRTC", "EnableCRTC",
    "GetPixelClock", "EnableVGA_Render", "EnableVGA_Access/GetSCLKOverMCLKRatio",
    "SetCRTC_Timing", "SetCRTC_OverScan", "SetCRTC_Replication",
    "SelectCRTC_Source", "EnableGraphSurfaces", "UpdateCRTC_DoubleBufferRegisters",
    "LUT_AutoFill", "EnableHW_IconCursor", "GetMemoryClock",
    "GetEngineClock", "SetCRTC_UsingDTDTiming", "ExternalEncoderControl",
    "LVTMAOutputControl", "VRAM_BlockDetectionByStrap", "MemoryCleanUp",
    "ReadEDIDFromHWAssistedI2C/ProcessI2cChannelTransaction",
    "WriteOneByteToHWAssistedI2C", "ReadHWAssistedI2CStatus/HPDInterruptService",
    "SpeedFanControl", "PowerConnectorDetection", "MC_Synchronization",
    "ComputeMemoryEnginePLL", "MemoryRefreshConversion", "VRAM_GetCurrentInfoBlock",
    "DynamicMemorySettings", "MemoryTraining", "EnableSpreadSpectrumOnPPLL",
    "TMDSAOutputControl", "SetVoltage", "DAC1OutputControl",
    "DAC2OutputControl", "SetupHWAssistedI2CStatus", "ClockSource",
    "MemoryDeviceInit", "EnableYUV", "DIG1EncoderControl",
    "DIG2EncoderControl", "DIG1TransmitterControl/UNIPHYTransmitterControl",
    "DIG2TransmitterControl/LVTMATransmitterControl",
    "ProcessAuxChannelTransaction", "DPEncoderService", "GetVoltageInfo"
};

// Tabela de dados (já mencionada acima) referente às funções encontradas na BIOS ATOM:
const std::vector<std::string> INDEX_DATA_TABLE = {
    "UtilityPipeLine", "MultimediaCapabilityInfo", "MultimediaConfigInfo",
    "StandardVESA_Timing", "FirmwareInfo", "DAC_Info",
    "LVDS_Info", "TMDS_Info", "AnalogTV_Info",
    "SupportedDevicesInfo", "GPIO_I2C_Info", "VRAM_UsageByFirmware",
    "GPIO_Pin_LUT", "VESA_ToInternalModeLUT", "ComponentVideoInfo",
    "PowerPlayInfo", "CompassionateData", "SaveRestoreInfo/DispDevicePriorityInfo",
    "PPLL_SS_Info/SS_Info", "OemInfo", "XTMDS_Info",
    "MclkSS_Info", "Object_Info/Object_Header", "IndirectIOAccess",
    "MC_InitParameter/AdjustARB_SEQ", "ASIC_VDDC_Info", "ASIC_InternalSS_Info/ASIC_MVDDC_Info",
    "TV_VideoMode/DispOutInfo", "VRAM_Info", "MemoryTrainingInfo/ASIC_MVDDQ_Info",
    "IntegratedSystemInfo", "ASIC_ProfilingInfo/ASIC_VDDCI_Info",
    "VoltageObjectInfo/VRAM_GPIO_DetectionInfo", "PowerSourceInfo"
};

// Helper para ler valores do arquivo binário.
// Usado no projeto para ler offsets e tamanhos das tabelas de comando e dados:
uint16_t readUShort(std::ifstream& file, uint16_t offset) {
    file.seekg(offset, std::ios::beg);
    uint16_t value;
    file.read(reinterpret_cast<char*>(&value), sizeof(value));
    return value;
}

// Helper para ler *um* byte do arquivo binário.
// É utilizado para ler os valores de revisão (major e minor) das tabelas de dados, além de outros usos pontuais:
uint8_t readByte(std::ifstream& file, uint16_t offset) {
    file.seekg(offset, std::ios::beg);
    uint8_t value;
    file.read(reinterpret_cast<char*>(&value), sizeof(value));
    return value;
}

// Helper para exibição do report:
void printReportLine(int index, uint16_t offset, const std::string& tableName, std::ifstream& file, bool isData) {
    std::cout << "  " << std::setfill('0') << std::setw(4) << std::hex << index << ":   ";
    
    if (offset == 0) {
        std::cout << "-               (" << tableName << ")" << std::endl;
    } else {
        uint16_t length = readUShort(file, offset);
        std::cout << std::setw(4) << offset << "  Len " << std::setw(4) << length;
        
        if (isData) {
            uint8_t revMajor = readByte(file, offset + 2);
            uint8_t revMinor = readByte(file, offset + 3);
            std::cout << "  Rev " << std::setw(2) << (int)revMajor << ":" << std::setw(2) << (int)revMinor;
        }
        
        std::cout << "  (" << tableName << ")" << std::endl;
    }
}

// Helper para dumpar as tabelas de acordo com seus nomes:
void dumpHexTable(std::ifstream& file, uint16_t offset, uint16_t size, const std::string& name) {
    if (offset == 0 || size == 0) return;

    // Cria arquivo .txt com o nome da Data Table:
    std::ofstream out(name + ".txt");
    if (!out) {
        std::cerr << "Erro ao salvar tabela: " << name << std::endl;
        return;
    }

    std::vector<uint8_t> buffer(size);
    file.seekg(offset, std::ios::beg);
    file.read(reinterpret_cast<char*>(buffer.data()), size);

    // Escreve em hexadecimal
    for (size_t i = 0; i < buffer.size(); i++) {
        if (i % 16 == 0) out << std::endl;
        out << std::hex << std::setw(2) << std::setfill('0') << (int)buffer[i] << " ";
    }

    out << std::endl;
    out.close();
}

// Helper para extrair as tabelas em formato hexadecimal, de acordo com seus offsets:
void extractAllHexDataTables(std::ifstream& file, _ATOM_MASTER_DATA_TABLE& dataTable) {

    uint16_t* pDataOffsets = reinterpret_cast<uint16_t*>(&dataTable.ListOfDataTables);
    int numDataTables = sizeof(_ATOM_MASTER_LIST_OF_DATA_TABLES) / sizeof(uint16_t);

    for (int i = 0; i < numDataTables; i++) {
        uint16_t offset = pDataOffsets[i];

        if (offset == 0 || i >= INDEX_DATA_TABLE.size())
            continue;

        uint16_t size = readUShort(file, offset);
        std::string filename = INDEX_DATA_TABLE[i];

        // Remove caracteres inválidos para nome de arquivo
        for (auto& c : filename) {
            if (c == '/' || c == '\\' || c == ':') c = '_';
        }

        dumpHexTable(file, offset, size, filename);
        std::cout << "Salvo: " << filename << ".txt (Offset 0x" 
                  << std::hex << offset << ", Size " << size << ")" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso:" << argv[0] << " <vbios.rom > vbios.txt" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Erro: nao foi possivel abrir o arquivo: " << filename << std::endl;
        return 1;
    }

    // Header para localizar o offset do cabeçalho real:
    const int OFFSET_TO_POINTER_TO_ATOM_ROM_HEADER = 72; 

    // Lê o cabeçalho do arquivo:
    uint16_t atomRomHeaderOffset = readUShort(file, OFFSET_TO_POINTER_TO_ATOM_ROM_HEADER);
    _ATOM_ROM_HEADER romHeader;
    file.seekg(atomRomHeaderOffset, std::ios::beg);
    file.read(reinterpret_cast<char*>(&romHeader), sizeof(romHeader));

    // Valida a assinatura "ATOM" dentro do arquivo:
    if (romHeader.uaFirmWareSignature[0] != 'A' || 
        romHeader.uaFirmWareSignature[1] != 'T' || 
        romHeader.uaFirmWareSignature[2] != 'O' || 
        romHeader.uaFirmWareSignature[3] != 'M') {
        std::cerr << "Erro: assinatura invalida" << std::endl;
        return 1;
    }

    // Aqui são exibidas algumas informações básicas a respeuto da BIOS processada:
    std::cout << "Dump do arquivo:" << std::endl << std::endl;
    std::cout << "Offset Header: 0x" << std::hex << atomRomHeaderOffset << std::endl;
    std::cout << "Assinatura: " << romHeader.uaFirmWareSignature[0] << romHeader.uaFirmWareSignature[1] 
              << romHeader.uaFirmWareSignature[2] << romHeader.uaFirmWareSignature[3] << std::endl;
    std::cout << "Offset do Command Table: 0x" << romHeader.usMasterCommandTableOffset << std::endl;
    std::cout << "Offset da Data Table: 0x" << romHeader.usMasterDataTableOffset << std::endl;
 

    // Processamento das tabelas de comando:
    _ATOM_MASTER_COMMAND_TABLE commandTable;
    file.seekg(romHeader.usMasterCommandTableOffset, std::ios::beg);
    file.read(reinterpret_cast<char*>(&commandTable), sizeof(commandTable));

    std::cout << "Command Tables:" << std::endl;
    
    uint16_t* pCmdOffsets = reinterpret_cast<uint16_t*>(&commandTable.ListOfCommandTables);
    int numCmdTables = sizeof(_ATOM_MASTER_LIST_OF_COMMAND_TABLES) / sizeof(uint16_t);

    for (int i = 0; i < numCmdTables; i++) {
        if (i < INDEX_COMMAND_TABLE.size()) {
            printReportLine(i, pCmdOffsets[i], INDEX_COMMAND_TABLE[i], file, false);
        }
    }

    std::cout << std::endl;

    // Processamento das tabelas de dados:
    _ATOM_MASTER_DATA_TABLE dataTable;
    file.seekg(romHeader.usMasterDataTableOffset, std::ios::beg);
    file.read(reinterpret_cast<char*>(&dataTable), sizeof(dataTable));

    std::cout << "Data Tables:" << std::endl;

    uint16_t* pDataOffsets = reinterpret_cast<uint16_t*>(&dataTable.ListOfDataTables);
    int numDataTables = sizeof(_ATOM_MASTER_LIST_OF_DATA_TABLES) / sizeof(uint16_t);

    for (int i = 0; i < numDataTables; i++) {
         if (i < INDEX_DATA_TABLE.size()) {
            printReportLine(i, pDataOffsets[i], INDEX_DATA_TABLE[i], file, true);
        }
    }

    // Se o usuário passou a flag --hex, fazemos o dump das tabelas
    bool dumpHex = false;
    if (argc >= 3 && std::string(argv[2]) == "--hex") {
        dumpHex = true;
    }

    if (dumpHex) {
        std::cout << "\nExtraindo Data Tables em hexadecimal..." << std::endl;
        extractAllHexDataTables(file, dataTable);
        std::cout << "Concluído!" << std::endl;
    }

    return 0;
}