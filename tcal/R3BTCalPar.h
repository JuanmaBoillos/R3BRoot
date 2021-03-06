#ifndef R3BTCALPAR_H
#define R3BTCALPAR_H

#define NMODULEMAX 6000

#include "FairParGenericSet.h" // for FairParGenericSet

#include "TObjArray.h"

#include "R3BTCalModulePar.h"

using namespace std;

class FairParamList;

/**
 * Parameter container for storing time calibration of a detector.
 * This class contains array of time calibration containers for each
 * module (of type R3BTCalModulePar). Instance of this class has to be
 * created using FairRuntimeDB::getContainer("name") method. Supported
 * names: LandTCalPar, LosTCalPar.
 * @author D. Kresan
 * @since September 3, 2015
 */
class R3BTCalPar : public FairParGenericSet
{

  public:
    /**
     * Standard constructor. Creates instance of this class.
     * @param name a name of container.
     * @param title a title of container.
     * @param context context/purpose for parameters and conditions.
     * @param own class ownership, if flag is kTRUE FairDB has the par.
     */
    R3BTCalPar(const char* name = "TCalPar",
               const char* title = "TCAL calibration",
               const char* context = "TestDefaultContext",
               Bool_t own = kTRUE);
    /**
     * Destructor. Cleares the memory used by the object.
     */
    virtual ~R3BTCalPar(void);

    /**
     * Method to reset the values of parameters.
     */
    void clear(void);

    /**
     * Method to store parameters using FairRuntimeDB.
     * @param list a list of parameters.
     */
    void putParams(FairParamList* list);

    /**
     * Method to retrieve parameters using FairRuntimeDB.
     * @param list a list of parameters.
     * @return kTRUE if successful, else kFALSE.
     */
    Bool_t getParams(FairParamList* list);

    /**
     * Method to print value of parameters to the standard output.
     * Calls printParams() for every module container.
     */
    void printParams();

    /**
     * Method to add parameter container for a module.
     * Extends the array.
     * @param tch a parameter container for a detector module.
     */
    void AddModulePar(R3BTCalModulePar* tch)
    {
        fTCalParams->Add(tch);
    }

    /**
     * Method to retrieve the arrray with module containers.
     * @return an array with parameter containers of type R3BTCalModulePar.
     */
    TObjArray* GetListOfModulePar()
    {
        return fTCalParams;
    }

    /**
     * Method to get number of modules storred in array.
     * @return size of array.
     */
    Int_t GetNumModulePar()
    {
        return fTCalParams->GetEntries();
    }

    /**
     * Method to get single parameter container for a specific module.
     * @param idx an index of a module.
     * @return parameter container of this module.
     */
    R3BTCalModulePar* GetModuleParAt(Int_t idx)
    {
        return (R3BTCalModulePar*)fTCalParams->At(idx);
    }

  private:
    const R3BTCalPar& operator=(const R3BTCalPar&); /**< an assignment operator */
    R3BTCalPar(const R3BTCalPar&);                  /**< a copy constructor */

    TObjArray* fTCalParams; /**< an array with parameter containers of all modules */

    ClassDef(R3BTCalPar, 1);
};

#endif /* !R3BTCALPAR_H*/
