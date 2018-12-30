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
/////////////////////////////////////////////////////////////////////////////
// IPointOnTerrainGE wrapper class

class IPointOnTerrainGE : public COleDispatchDriver
{
public:
	IPointOnTerrainGE() {}		// Calls COleDispatchDriver default constructor
	IPointOnTerrainGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IPointOnTerrainGE(const IPointOnTerrainGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetLatitude();
	double GetLongitude();
	double GetAltitude();
	long GetProjectedOntoGlobe();
	long GetZeroElevationExaggeration();
};
