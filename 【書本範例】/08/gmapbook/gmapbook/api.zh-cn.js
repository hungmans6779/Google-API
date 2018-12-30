var G_INCOMPAT=false;
function GScript(src){
	document.write('<'+'script src="'+src+'"'+' type="text/javascript"><'+'/script>');

}
function GBrowserIsCompatible(){
	if(G_INCOMPAT)return false;
	if(!window.RegExp)return false;
	var AGENTS=["opera","msie","safari","firefox","netscape","mozilla"];
	var agent=navigator.userAgent.toLowerCase();
	for(var i=0;i<AGENTS.length;i++){
		var agentStr=AGENTS[i];
		if(agent.indexOf(agentStr)!=-1){
			var versionExpr=new RegExp(agentStr+"[ \/]?([0-9]+(\.[0-9]+)?)");
			var version=0;
			if(versionExpr.exec(agent)!=null){
				version=parseFloat(RegExp.$1);
			}
			if(agentStr=="opera")return version>=7;
			if(agentStr=="safari")return version>=125;
			if(agentStr=="msie")return (version>=5.5&&agent.indexOf("powerpc")==-1);
			if(agentStr=="netscape")return version>7;
			if(agentStr=="firefox")return version>=0.8;

		}
	}
	return !!document.getElementById;

}

//這一行去處校驗
function GVerify(){

}

//這一行標誌圖片伺服器的位址http://mt0.google.cn/googlechina/maptile?v\x3dcn1\x26hl\x3dzh-CN\x26
function GLoad(){
	GLoadApi(["http://mt0.google.cn/googlechina/maptile?v\x3dcn1\x26hl\x3dzh-CN\x26"],
			["http://kh0.google.com/kh?n=404&v=17&","http://kh1.google.com/kh?n=404&v=17&","http://kh2.google.com/kh?n=404&v=17&","http://kh3.google.com/kh?n=404&v=17&"],
			["http://mt0.google.com/mt?n=404&v=w2t.47&","http://mt1.google.com/mt?n=404&v=w2t.47&","http://mt2.google.com/mt?n=404&v=w2t.47&","http://mt3.google.com/mt?n=404&v=w2t.47&"]);
	if(window.GJsLoaderInit){
		GJsLoaderInit("http://maps.google.com/mapfiles/73/maps2.api/main.js");

	}
}

function GUnload(){
	if(window.GUnloadApi){
		GUnloadApi();
	}

}

var _mFlags={};
var _mHost="http://ditu.google.cn";
var _mUri="/maps";
var _mDomain="google.tw";
var _mStaticPath="http://www.google.cn/intl/zh-CN_cn/mapfiles/";
var _mTermsUrl="http://www.google.cn/intl/zh-CN_cn/help/terms_local.html";
var _mTerms="使用條款";
var _mMapMode="地圖";
var _mMapModeShort="地圖";
var _mMapError="很抱歉，在這一縮放級別的地圖上未找到此區域。<p>請縮小地圖，擴大視野範圍。</p>";
var _mSatelliteMode="衛星";
var _mSatelliteModeShort="星期六";
var _mSatelliteError="很抱歉，在這一縮放級別的成像上未找到此區域。<p>請縮小成像，擴大視野範圍。</p>";
var _mHybridMode="混合地圖";
var _mHybridModeShort="混合地圖";
var _mSatelliteToken="fzwq1JXT3xA-aAS05AxQE0iP0Q-bN4oSjRGTFA";
var _mZoomIn="放大";
var _mZoomOut="縮小";
var _mZoomSet="按一下設置縮放水準";
var _mZoomDrag="拖動縮放";
var _mPanWest="向左平移";
var _mPanEast="向右平移";
var _mPanNorth="向上平移";
var _mPanSouth="向下平移";
var _mLastResult="返回上一結果";
var _mMapCopy="地圖資料 &#169;2007";
var _mSatelliteCopy="Imagery &#169;2007";
var _mGoogleCopy="&#169;2007 Google";
var _mKilometers="公里";
var _mMiles="英里";
var _mMeters="米";
var _mFeet="英尺";
var _mPreferMetric=true;
var _mPanelWidth=20;
var _mTabBasics="地址";
var _mTabDetails="詳細資料";
var _mDecimalPoint='.';
var _mThousandsSeparator=',';
var _mUsePrintLink='要查看螢幕上的所有細節，請使用地圖旁邊的"列印"連結。';
var _mPrintSorry='';
var _mMapPrintUrl='http://www.google.com/mapprint';
var _mPrint='列印';
var _mOverview='概要';
var _mStart='起始地點';
var _mEnd='目的地';
var _mStep='第 %1$s 步';
var _mStop='目的地 %1$s';
var _mHideAllMaps='隱藏地圖';
var _mShowAllMaps='顯示所有地圖';
var _mUnHideMaps='顯示地圖';
var _mShowLargeMap='顯示原始地圖視圖。';
var _mmControlTitle=null;
var _mAutocompleteFrom='從';
var _mAutocompleteTo='至';
var _mAutocompleteNearRe='^(?:(?:.*?)&#92;s+)(?:(?:in|near|around|close to):?&#92;s+)(.+)$';
var _mSvgEnabled=true;
var _mSvgForced=false;
var _mStreetMapAlt='顯示街道地圖';
var _mSatelliteMapAlt='顯示衛星圖片';
var _mHybridMapAlt='顯示標有街道名稱的圖片';
var _mSeeOnGoogleMaps="點擊可在 Google 地圖上參看該區域";
var _mLogInfoWinExp=true;
var _mLogPanZoomClks=false;
var _mLogWizard=true;
var _mTransitV2=false;
function GLoadMapsScript(){
	if(GBrowserIsCompatible()){
		GScript("http://maps.google.com/mapfiles/73/maps2.api/main.js");
	}
}
GLoadMapsScript();
