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
// ITimeIntervalGE wrapper class

class ITimeIntervalGE : public COleDispatchDriver
{
public:
	ITimeIntervalGE() {}		// Calls COleDispatchDriver default constructor
	ITimeIntervalGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITimeIntervalGE(const ITimeIntervalGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetBeginTime();
	LPDISPATCH GetEndTime();
};
/////////////////////////////////////////////////////////////////////////////
// ITimeGE wrapper class

class ITimeGE : public COleDispatchDriver
{
public:
	ITimeGE() {}		// Calls COleDispatchDriver default constructor
	ITimeGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITimeGE(const ITimeGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetType();
	void SetType(long nNewValue);
	long GetYear();
	void SetYear(long nNewValue);
	long GetMonth();
	void SetMonth(long nNewValue);
	long GetDay();
	void SetDay(long nNewValue);
	long GetHour();
	void SetHour(long nNewValue);
	long GetMinute();
	void SetMinute(long nNewValue);
	long GetSecond();
	void SetSecond(long nNewValue);
	double GetTimeZone();
	void SetTimeZone(double newValue);
	LPDISPATCH Clone();
	LPDISPATCH ConvertToZone(double TimeZone);
};
/////////////////////////////////////////////////////////////////////////////
// ITourControllerGE wrapper class

class ITourControllerGE : public COleDispatchDriver
{
public:
	ITourControllerGE() {}		// Calls COleDispatchDriver default constructor
	ITourControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITourControllerGE(const ITourControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void PlayOrPause();
	void Stop();
	double GetSpeed();
	void SetSpeed(double newValue);
	double GetPauseDelay();
	void SetPauseDelay(double newValue);
	long GetCycles();
	void SetCycles(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// IAnimationControllerGE wrapper class

class IAnimationControllerGE : public COleDispatchDriver
{
public:
	IAnimationControllerGE() {}		// Calls COleDispatchDriver default constructor
	IAnimationControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAnimationControllerGE(const IAnimationControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Play();
	void Pause();
	LPDISPATCH GetSliderTimeInterval();
	LPDISPATCH GetCurrentTimeInterval();
	void SetCurrentTimeInterval(LPDISPATCH newValue);
};
