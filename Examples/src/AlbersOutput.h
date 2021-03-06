#ifndef _ALBERSOUTPUT_H_
#define _ALBERSOUTPUT_H_

#include "GaudiAlg/GaudiAlgorithm.h"
#include "albers/CollectionBase.h"
#include "albers/Registry.h"
// ROOT specific includes
#include "TTree.h"

// forward declarations
class TFile;
class AlbersDataSvc;

class AlbersOutput : public GaudiAlgorithm {
  friend class AlgFactory<AlbersOutput> ;

public:
  /// Constructor.
  AlbersOutput(const std::string& name, ISvcLocator* svcLoc);
  /// Initialize.
  virtual StatusCode initialize();
  /// Execute.
  virtual StatusCode execute();
  /// Finalize.
  virtual StatusCode finalize();

private:
  bool m_first;
  std::string m_filename;
  albers::Registry* m_registry;
  AlbersDataSvc* m_albersDataSvc;
  TFile* m_file;
  TTree* m_datatree;
  TTree* m_metadatatree;
  std::vector<albers::CollectionBase*> m_storedCollections;

};

#endif
