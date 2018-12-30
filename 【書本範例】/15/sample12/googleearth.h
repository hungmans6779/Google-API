// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IApplicationGE wrapper class

class IApplicationGE : public COleDispatchDriver
{
public:
	IApplicationGE() {}		// Calls COleDispatchDriver default constructor
	IApplicationGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IApplicationGE(const IApplicationGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetCamera(long considerTerrain);
	void SetCamera(LPDISPATCH camera, double speed);
	void SetCameraParams(double lat, double lon, double alt, long altMode, double Range, double Tilt, double Azimuth, double speed);
	long GetStreamingProgressPercentage();
	void SaveScreenShot(LPCTSTR fileName, long quality);
	void OpenKmlFile(LPCTSTR fileName, long suppressMessages);
	void LoadKmlData(BSTR* kmlData);
	double GetAutoPilotSpeed();
	void SetAutoPilotSpeed(double newValue);
	LPDISPATCH GetViewExtents();
	LPDISPATCH GetFeatureByName(LPCTSTR Name);
	LPDISPATCH GetFeatureByHref(LPCTSTR href);
	void SetFeatureView(LPDISPATCH feature, double speed);
	LPDISPATCH GetPointOnTerrainFromScreenCoords(double screen_x, double screen_y);
	long GetVersionMajor();
	long GetVersionMinor();
	long GetVersionBuild();
	long GetVersionAppType();
	long IsInitialized();
	long IsOnline();
	void Login();
	void Logout();
	void ShowDescriptionBalloon(LPDISPATCH feature);
	void HideDescriptionBalloons();
	LPDISPATCH GetHighlightedFeature();
	LPDISPATCH GetMyPlaces();
	LPDISPATCH GetTemporaryPlaces();
	LPDISPATCH GetLayersDatabases();
	double GetElevationExaggeration();
	void SetElevationExaggeration(double newValue);
	long GetMainHwnd();
	LPDISPATCH GetTourController();
	LPDISPATCH GetSearchController();
	LPDISPATCH GetAnimationController();
	long GetRenderHwnd();
};
/////////////////////////////////////////////////////////////////////////////
// IFeatureGE wrapper class

class IFeatureGE : public COleDispatchDriver
{
public:
	IFeatureGE() {}		// Calls COleDispatchDriver default constructor
	IFeatureGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IFeatureGE(const IFeatureGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	long GetVisibility();
	void SetVisibility(long nNewValue);
	long GetHasView();
	long GetHighlighted();
	void Highlight();
	LPDISPATCH GetParent();
	LPDISPATCH GetChildren();
	LPDISPATCH GetTimeInterval();
};
/////////////////////////////////////////////////////////////////////////////
// IFeatureCollectionGE wrapper class

class IFeatureCollectionGE : public COleDispatchDriver
{
public:
	IFeatureCollectionGE() {}		// Calls COleDispatchDriver default constructor
	IFeatureCollectionGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IFeatureCollectionGE(const IFeatureCollectionGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH GetItem(long index);
	long GetCount();
};
/////////////////////////////////////////////////////////////////////////////
// ISearchControllerGE wrapper class

class ISearchControllerGE : public COleDispatchDriver
{
public:
	ISearchControllerGE() {}		// Calls COleDispatchDriver default constructor
	ISearchControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISearchControllerGE(const ISearchControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Search(LPCTSTR searchString);
	long IsSearchInProgress();
	LPDISPATCH GetResults();
	void ClearResults();
};
/////////////////////////////////////////////////////////////////////////////
// ICameraInfoGE wrapper class

class ICameraInfoGE : public COleDispatchDriver
{
public:
	ICameraInfoGE() {}		// Calls COleDispatchDriver default constructor
	ICameraInfoGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ICameraInfoGE(const ICameraInfoGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetFocusPointLatitude();
	void SetFocusPointLatitude(double newValue);
	double GetFocusPointLongitude();
	void SetFocusPointLongitude(double newValue);
	double GetFocusPointAltitude();
	void SetFocusPointAltitude(double newValue);
	long GetFocusPointAltitudeMode();
	void SetFocusPointAltitudeMode(long nNewValue);
	double GetRange();
	void SetRange(double newValue);
	double GetTilt();
	void SetTilt(double newValue);
	double GetAzimuth();
	void SetAzimuth(double newValue);
};
