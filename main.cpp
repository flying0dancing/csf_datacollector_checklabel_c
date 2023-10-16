
#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

namespace {
const string kImplantShortName     = "Impl";
const string kDentureShortName     = "Dnt";
const string kImpressionShortName  = "Impr";
const string kPreparationShortName = "Prp";
const string kExtraShortName       = "Ext";
const string kExtraBiteShortName   = "Exb";

const string kCSZXSuffix    = "cszx";
const string kRecordsName   = "_records";
const string kRecordsSuffix = "zip";
const string kVideoSuffix   = "mp4";
}  // namespace
//void init_exist_map();
map<int, string> init_map();
string get_catalog_str(std::list<int> names);
int verify(int a1[],int size,string tag);

typedef enum _AcquisitionCatalog {
  UNKNOWN_JAW = -2,  // error flag
  ANY_JAW = -1,      // algo use
  LOWER_JAWER = 0,
  UPPER_JAWER = 1,
  BUCCAL = 2,
  LOWER_JAWER_IMPLANT = 3,
  UPPER_JAWER_IMPLANT = 4,
  BUCCAL_CAPTURING = 5,
  LOWER_JAWER_DUAL = 6,
  UPPER_JAWER_DUAL = 7,
  LOWER_EDENTULOUS = 8,
  UPPER_EDENTULOUS = 9,


  BITE_1 = 11,
  BITE_2 = 12,
  BITE_3 = 13,
  BITE_4 = 14,
  BITE_5 = 15,
  BITE_6 = 16,

  LOWER_IMPRESSION_1 = 21,
  LOWER_IMPRESSION_2 = 22,
  LOWER_IMPRESSION_3 = 23,

  UPPER_IMPRESSION_1 = 31,
  UPPER_IMPRESSION_2 = 32,
  UPPER_IMPRESSION_3 = 33,

  LOWER_POSTSCAN_IMPRESSION_1 = 41,
  LOWER_POSTSCAN_IMPRESSION_2 = 42,
  LOWER_POSTSCAN_IMPRESSION_3 = 43,

  UPPER_POSTSCAN_IMPRESSION_1 = 51,
  UPPER_POSTSCAN_IMPRESSION_2 = 52,
  UPPER_POSTSCAN_IMPRESSION_3 = 53,

  LOWER_IMPLANT_IMPRESSION_1 = 61,
  LOWER_IMPLANT_IMPRESSION_2 = 62,
  LOWER_IMPLANT_IMPRESSION_3 = 63,

  UPPER_IMPLANT_IMPRESSION_1 = 71,
  UPPER_IMPLANT_IMPRESSION_2 = 72,
  UPPER_IMPLANT_IMPRESSION_3 = 73,

  LOWER_EDENTULOUS_IMPRESSION_1 = 81,
  LOWER_EDENTULOUS_IMPRESSION_2 = 82,
  LOWER_EDENTULOUS_IMPRESSION_3 = 83,

  UPPER_EDENTULOUS_IMPRESSION_1 = 91,
  UPPER_EDENTULOUS_IMPRESSION_2 = 92,
  UPPER_EDENTULOUS_IMPRESSION_3 = 93,

  // extra bite group 1
  BITE_7 = 100,
  BITE_8 = 101,
  BITE_9 = 102,
  BITE_10 = 103,
  BITE_11 = 104,
  BITE_12 = 105,

  // extra bite group 2
  BITE_13 = 106,
  BITE_14 = 107,
  BITE_15 = 108,
  BITE_16 = 109,
  BITE_17 = 110,
  BITE_18 = 111,

  // extra bite group 3
  BITE_19 = 112,
  BITE_20 = 113,
  BITE_21 = 114,
  BITE_22 = 115,
  BITE_23 = 116,
  BITE_24 = 117,

  // extra bite group 4
  BITE_25 = 118,
  BITE_26 = 119,
  BITE_27 = 120,
  BITE_28 = 121,
  BITE_29 = 122,
  BITE_30 = 123,

  LOWER_EMERGENCE_PROFILE = 130,
  UPPER_EMERGENCE_PROFILE = 131,

  LOWER_DENTURE = 140,
  UPPER_DENTURE = 141,

  EXTRA_JAW_1 = 200,
  EXTRA_JAW_2 = 201,
  EXTRA_JAW_3 = 202,
  CATALOG_TYPE_COUNT
} AcquisitionCatalog;

map<int, string> init_map(){
 map<int, string> cat_name_map_ = {
    {LOWER_JAWER_IMPLANT, kImplantShortName},
    {UPPER_JAWER_IMPLANT, kImplantShortName},
    {LOWER_EMERGENCE_PROFILE, kImplantShortName},
    {UPPER_EMERGENCE_PROFILE, kImplantShortName},

    {LOWER_JAWER_DUAL, kPreparationShortName},
    {UPPER_JAWER_DUAL, kPreparationShortName},

    {LOWER_EDENTULOUS, kDentureShortName},
    {UPPER_EDENTULOUS, kDentureShortName},
    {LOWER_DENTURE, kDentureShortName},
    {UPPER_DENTURE, kDentureShortName},

    {LOWER_IMPRESSION_1, kImpressionShortName},
    {LOWER_IMPRESSION_2, kImpressionShortName},
    {LOWER_IMPRESSION_3, kImpressionShortName},
    {UPPER_IMPRESSION_1, kImpressionShortName},
    {UPPER_IMPRESSION_2, kImpressionShortName},
    {UPPER_IMPRESSION_3, kImpressionShortName},
    {LOWER_POSTSCAN_IMPRESSION_1, kImpressionShortName},
    {LOWER_POSTSCAN_IMPRESSION_2, kImpressionShortName},
    {LOWER_POSTSCAN_IMPRESSION_3, kImpressionShortName},
    {UPPER_POSTSCAN_IMPRESSION_1, kImpressionShortName},
    {UPPER_POSTSCAN_IMPRESSION_2, kImpressionShortName},
    {UPPER_POSTSCAN_IMPRESSION_3, kImpressionShortName},
    {LOWER_IMPLANT_IMPRESSION_1, kImpressionShortName},
    {LOWER_IMPLANT_IMPRESSION_2, kImpressionShortName},
    {LOWER_IMPLANT_IMPRESSION_3, kImpressionShortName},
    {UPPER_IMPLANT_IMPRESSION_1, kImpressionShortName},
    {UPPER_IMPLANT_IMPRESSION_2, kImpressionShortName},
    {UPPER_IMPLANT_IMPRESSION_3, kImpressionShortName},
    {LOWER_EDENTULOUS_IMPRESSION_1, kImpressionShortName},
    {LOWER_EDENTULOUS_IMPRESSION_2, kImpressionShortName},
    {LOWER_EDENTULOUS_IMPRESSION_3, kImpressionShortName},
    {UPPER_EDENTULOUS_IMPRESSION_1, kImpressionShortName},
    {UPPER_EDENTULOUS_IMPRESSION_2, kImpressionShortName},
    {UPPER_EDENTULOUS_IMPRESSION_3, kImpressionShortName},

    {BITE_7, kExtraBiteShortName},
    {BITE_8, kExtraBiteShortName},
    {BITE_9, kExtraBiteShortName},
    {BITE_10, kExtraBiteShortName},
    {BITE_11, kExtraBiteShortName},
    {BITE_12, kExtraBiteShortName},
    {BITE_13, kExtraBiteShortName},
    {BITE_14, kExtraBiteShortName},
    {BITE_15, kExtraBiteShortName},
    {BITE_16, kExtraBiteShortName},
    {BITE_17, kExtraBiteShortName},
    {BITE_18, kExtraBiteShortName},
    {BITE_19, kExtraBiteShortName},
    {BITE_20, kExtraBiteShortName},
    {BITE_21, kExtraBiteShortName},
    {BITE_22, kExtraBiteShortName},
    {BITE_23, kExtraBiteShortName},
    {BITE_24, kExtraBiteShortName},
    {BITE_25, kExtraBiteShortName},
    {BITE_26, kExtraBiteShortName},
    {BITE_27, kExtraBiteShortName},
    {BITE_28, kExtraBiteShortName},
    {BITE_29, kExtraBiteShortName},
    {BITE_30, kExtraBiteShortName},

    {EXTRA_JAW_1, kExtraShortName},
    {EXTRA_JAW_2, kExtraShortName},
    {EXTRA_JAW_3, kExtraShortName},
  };
  return cat_name_map_;
  }
/*
QString MainWindow::get_catalog_string(const QFileInfo& csz_file) {
  if (!csz_file.exists() || csz_file.suffix().toUpper() != kCSZXSuffix.toUpper()) {
    return "";
  }
  QString catalog_str{""};
  init_exist_map();
  QuaZip zip{csz_file.absoluteFilePath()};
  zip.open(QuaZip::mdUnzip);
  QStringList names = zip.getFileNameList();
  for (auto name : names) {
    if (name.startsWith("MultiViews_")) {
      QStringList strs = name.replace("MultiViews_", "").split(".");
      if (strs.size() > 1) {
        auto catalog = strs[0].toInt();
        if (cat_name_map_.find(catalog) != cat_name_map_.end()) {
          if (!cat_exist_map_[cat_name_map_[catalog]]) {
            catalog_str += "_" + cat_name_map_[catalog];
            cat_exist_map_[cat_name_map_[catalog]] = true;
          }
        }
      }
    }
  }
  return catalog_str;
}
*/



/*void init_exist_map() {
  cat_exist_map_.clear();
  cat_exist_map_[kImplantShortName]     = false;
  cat_exist_map_[kDentureShortName]     = false;
  cat_exist_map_[kImpressionShortName]  = false;
  cat_exist_map_[kPreparationShortName] = false;
  cat_exist_map_[kExtraShortName]       = false;
  cat_exist_map_[kExtraBiteShortName]   = false;

}
*/
string get_catalog_str(std::list<int> names){
  map<int,string> cat_name_map_=init_map();
  string catalog_str{""};
  //init_exist_map();
  map<string,bool> cat_exist_map_={};
  cat_exist_map_.clear();
  cat_exist_map_[kImplantShortName]     = false;
  cat_exist_map_[kDentureShortName]     = false;
  cat_exist_map_[kImpressionShortName]  = false;
  cat_exist_map_[kPreparationShortName] = false;
  cat_exist_map_[kExtraShortName]       = false;
  cat_exist_map_[kExtraBiteShortName]   = false;
  for (auto name: names){
    auto catalog = name;
        if (cat_name_map_.find(catalog) != cat_name_map_.end()) {
          if (!cat_exist_map_[cat_name_map_[catalog]]) {
            catalog_str += "_" + cat_name_map_[catalog];
            cat_exist_map_[cat_name_map_[catalog]] = true;
          }
        }

  }

  return catalog_str;
}
int verify(int a1[],int size,string tag){
   int fail=0;
   std::list<int> row;
    list<int>::iterator p1;
    std::cout<<"identifier compare with workflow"<<std::endl;
    for(int i=0;i<size;i++){
        row.push_back(a1[i]);
        for(p1=row.begin();p1!=row.end();p1++){
            std::cout<<to_string(*p1)+" : "+tag;
        }
        if(get_catalog_str(row).compare(tag) == 0){
            std::cout<<"   pass"<<std::endl;
        }else{
            std::cout<<"   fail"<<std::endl;
            fail++;
        }
        row.pop_back();
    }
    return fail;
}


int main(){
   
    int a0[] = { 3,4,130,131};//Impl
    int a2[] = { 6,7};//Prp
    int a3[] = { 8,9,140,141};//Dnt
    int a4[] = { 200,201,202};//Ext
    int a5[24];//Exb
    int a6[]={21,22,23,31,32,33,41,42,43,51,52,53,61,62,63,71,72,73,81,82,83,91,92,93};//Impr
    int i=100;//100-123
    for(int i=0;i<24;i++){
       a5[i]=i+100;
    }
    
    int failcount=verify( a0,4,{"_Impl"});
    failcount=failcount+verify(a2,2,{"_Prp"});
    failcount+=verify(a3,4,{"_Dnt"});
    failcount+=verify(a4,3,{"_Ext"});
    failcount+=verify(a5,24,{"_Exb"});//Exb
    failcount+=verify(a6,24,{"_Impr"});//
    std::cout<<failcount<<std::endl;
    return failcount;
}