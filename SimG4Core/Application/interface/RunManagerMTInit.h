#ifndef SimG4Core_RunManagerMTInit_H
#define SimG4Core_RunManagerMTInit_H

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESWatcher.h"
 
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"

#include <string>
#include <vector>

class DDCompactView;
class MagneticField;

namespace HepPDT {
  class ParticleDataTable;
}

class RunManagerMTInit {
public:
  explicit RunManagerMTInit(const edm::ParameterSet& iConfig);
  ~RunManagerMTInit();

  const edm::ParameterSet& parameterSet() const { return m_p; }

  struct ESProducts {
    ESProducts(): pDD(nullptr), pMF(nullptr), pTable(nullptr) {}
    const DDCompactView *pDD;
    const MagneticField *pMF;
    const HepPDT::ParticleDataTable *pTable;
  };
  ESProducts readES(const edm::EventSetup& iSetup);

private:
  edm::ParameterSet m_p;

  edm::ESWatcher<IdealGeometryRecord> idealGeomRcdWatcher_;
  edm::ESWatcher<IdealMagneticFieldRecord> idealMagRcdWatcher_;

  bool firstRun;
  const bool m_pUseMagneticField;
};

#endif
