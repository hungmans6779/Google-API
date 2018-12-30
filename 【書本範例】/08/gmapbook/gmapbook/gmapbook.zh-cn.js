/*-------------------------------------------------
GButton類定義，穩定版
--------------------------------------------------*/
function GButton(b){
	this.anchor=b.anchor;
	this.offset=new GSize(b.offset.x,b.offset.y);
	this.caption=b.caption;
	this.div=document.createElement("div");
	with(this.div){
		unselectable="on";
		onselectstart=function(){
			return false;
		};
		with(style){
			MozUserSelect="none";
			zIndex=1;
			cursor=b.cursor||"pointer";
			position=b.position||"absolute";
			fontSize=b.fontSize||"12px";
			fontFamily=b.fontFamily||"Arial, sans serif";
			border=b.border||"solid 1px black";
			textAlign=b.textAlign||"center";
			padding=b.padding||"3px";
			margin=b.margin||"0";
			width=b.width||"60px";
			b.height?(height=b.height):null;
			color=b.color||"black";
			background=b.background||"white";
		}
	};
};

//指定GButton的prototype，即繼承自GControl
GButton.prototype=new GControl(true,false);

//這裡是初始化函數 a其實是GMap物件
GButton.prototype.initialize=function(a){
	a.getContainer().appendChild(this.div);
	GEvent.bindDom(this.div,"click",this,this.onClick);
	return this.div;
};
GButton.prototype.onClick=function(){
	GEvent.trigger(this,"click");
};
//可將簡單的BBCode轉為XHTML
GButton.prototype.formatCation=function(str){
	var filters=[[/\[b\](.+?)\[\/b\]/,"<strong>","</strong>"],[/\[i\](.+?)\[\/i\]/,"<em>","</em>"],[/\[u\](.+?)\[\/u\]/,"<span style=\"text-decoration:underline\">","</span>"],[/\[s\](.+?)\[\/s\]/,"<span style=\"text-decoration:line-through\">","</span>"]];
	for(var i=0;i<filters.length;i++){
		while(filters[i][0].test(str))str=str.replace(filters[i][0],filters[i][1]+RegExp.$1+filters[i][2]);
	};
	return str;
};

//添加按鈕，同時添加事件
//a為GMap2物件，action為回應函數
GButton.prototype.add=function(a,action){
	this.div.innerHTML=this.formatCation(this.caption);
	a.addControl(this,new GControlPosition(this.anchor,this.offset));
	GEvent.addListener(this,"click",action);
};

//顯示
GButton.prototype.show=function(){
	this.div.style.display="block";
};

//隱藏
GButton.prototype.hide=function(){
	this.div.style.display="none";
};

//設定標題
GButton.prototype.setCaption=function(caption){
	this.caption=caption;
	this.div.innerHTML=this.formatCation(this.caption);
};




/*-------------------------------------------------
MD5演算法，到處都是
--------------------------------------------------*/

var hex_chr="0123456789abcdef";
function rhex(num){
	str="";
	for(j=0;j<=3;j++)str+=hex_chr.charAt((num>>(j*8+4))&0x0F)+hex_chr.charAt((num>>(j*8))&0x0F);
	return str;
}
function str2blks_MD5(str){
	nblk=((str.length+8)>>6)+1;
	blks=new Array(nblk*16);
	for(i=0;i<nblk*16;i++)blks[i]=0;
	for(i=0;i<str.length;i++)blks[i>>2]|=str.charCodeAt(i)<<((i%4)*8);
	blks[i>>2]|=0x80<<((i%4)*8);
	blks[nblk*16-2]=str.length*8;
	return blks;
}
function add(x,y){
	var lsw=(x&0xFFFF)+(y&0xFFFF);
	var msw=(x>>16)+(y>>16)+(lsw>>16);
	return(msw<<16)|(lsw&0xFFFF);
}
function rol(num,cnt){
	return(num<<cnt)|(num>>>(32-cnt));
}
function cmn(q,a,b,x,s,t){
	return add(rol(add(add(a,q),add(x,t)),s),b);
}
function ff(a,b,c,d,x,s,t){
	return cmn((b&c)|((~b)&d),a,b,x,s,t);
}
function gg(a,b,c,d,x,s,t){
	return cmn((b&d)|(c&(~d)),a,b,x,s,t);
}
function hh(a,b,c,d,x,s,t){
	return cmn(b ^ c ^ d,a,b,x,s,t);
}
function ii(a,b,c,d,x,s,t){
	return cmn(c ^(b|(~d)),a,b,x,s,t);
}
function calcMD5(str){
	x=str2blks_MD5(str);
	a=1732584193;
	b=-271733879;
	c=-1732584194;
	d=271733878;
	for(i=0;i<x.length;i+=16){
		olda=a;
		oldb=b;
		oldc=c;
		oldd=d;
		a=ff(a,b,c,d,x[i+0],7,-680876936);
		d=ff(d,a,b,c,x[i+1],12,-389564586);
		c=ff(c,d,a,b,x[i+2],17,606105819);
		b=ff(b,c,d,a,x[i+3],22,-1044525330);
		a=ff(a,b,c,d,x[i+4],7,-176418897);
		d=ff(d,a,b,c,x[i+5],12,1200080426);
		c=ff(c,d,a,b,x[i+6],17,-1473231341);
		b=ff(b,c,d,a,x[i+7],22,-45705983);
		a=ff(a,b,c,d,x[i+8],7,1770035416);
		d=ff(d,a,b,c,x[i+9],12,-1958414417);
		c=ff(c,d,a,b,x[i+10],17,-42063);
		b=ff(b,c,d,a,x[i+11],22,-1990404162);
		a=ff(a,b,c,d,x[i+12],7,1804603682);
		d=ff(d,a,b,c,x[i+13],12,-40341101);
		c=ff(c,d,a,b,x[i+14],17,-1502002290);
		b=ff(b,c,d,a,x[i+15],22,1236535329);
		a=gg(a,b,c,d,x[i+1],5,-165796510);
		d=gg(d,a,b,c,x[i+6],9,-1069501632);
		c=gg(c,d,a,b,x[i+11],14,643717713);
		b=gg(b,c,d,a,x[i+0],20,-373897302);
		a=gg(a,b,c,d,x[i+5],5,-701558691);
		d=gg(d,a,b,c,x[i+10],9,38016083);
		c=gg(c,d,a,b,x[i+15],14,-660478335);
		b=gg(b,c,d,a,x[i+4],20,-405537848);
		a=gg(a,b,c,d,x[i+9],5,568446438);
		d=gg(d,a,b,c,x[i+14],9,-1019803690);
		c=gg(c,d,a,b,x[i+3],14,-187363961);
		b=gg(b,c,d,a,x[i+8],20,1163531501);
		a=gg(a,b,c,d,x[i+13],5,-1444681467);
		d=gg(d,a,b,c,x[i+2],9,-51403784);
		c=gg(c,d,a,b,x[i+7],14,1735328473);
		b=gg(b,c,d,a,x[i+12],20,-1926607734);
		a=hh(a,b,c,d,x[i+5],4,-378558);
		d=hh(d,a,b,c,x[i+8],11,-2022574463);
		c=hh(c,d,a,b,x[i+11],16,1839030562);
		b=hh(b,c,d,a,x[i+14],23,-35309556);
		a=hh(a,b,c,d,x[i+1],4,-1530992060);
		d=hh(d,a,b,c,x[i+4],11,1272893353);
		c=hh(c,d,a,b,x[i+7],16,-155497632);
		b=hh(b,c,d,a,x[i+10],23,-1094730640);
		a=hh(a,b,c,d,x[i+13],4,681279174);
		d=hh(d,a,b,c,x[i+0],11,-358537222);
		c=hh(c,d,a,b,x[i+3],16,-722521979);
		b=hh(b,c,d,a,x[i+6],23,76029189);
		a=hh(a,b,c,d,x[i+9],4,-640364487);
		d=hh(d,a,b,c,x[i+12],11,-421815835);
		c=hh(c,d,a,b,x[i+15],16,530742520);
		b=hh(b,c,d,a,x[i+2],23,-995338651);
		a=ii(a,b,c,d,x[i+0],6,-198630844);
		d=ii(d,a,b,c,x[i+7],10,1126891415);
		c=ii(c,d,a,b,x[i+14],15,-1416354905);
		b=ii(b,c,d,a,x[i+5],21,-57434055);
		a=ii(a,b,c,d,x[i+12],6,1700485571);
		d=ii(d,a,b,c,x[i+3],10,-1894986606);
		c=ii(c,d,a,b,x[i+10],15,-1051523);
		b=ii(b,c,d,a,x[i+1],21,-2054922799);
		a=ii(a,b,c,d,x[i+8],6,1873313359);
		d=ii(d,a,b,c,x[i+15],10,-30611744);
		c=ii(c,d,a,b,x[i+6],15,-1560198380);
		b=ii(b,c,d,a,x[i+13],21,1309151649);
		a=ii(a,b,c,d,x[i+4],6,-145523070);
		d=ii(d,a,b,c,x[i+11],10,-1120210379);
		c=ii(c,d,a,b,x[i+2],15,718787259);
		b=ii(b,c,d,a,x[i+9],21,-343485551);
		a=add(a,olda);
		b=add(b,oldb);
		c=add(c,oldc);
		d=add(d,oldd);
	}
	return rhex(a)+rhex(b)+rhex(c)+rhex(d);
};


/*-------------------------------------------------
為陣列添加indexOf方法，Firefox不需要
Mysql無法保存JS的地圖類型物件，因此用陣列序號進行保存
--------------------------------------------------*/
[].indexOf||(Array.prototype.indexOf=function(v){
	for(var i=this.length;i--&&this[i]!==v;);
	return i;
});


/*-------------------------------------------------
藍色的提示資訊的視窗
GMapbookInfo類參考了國外的一個類，做了一些必要的改動
--------------------------------------------------*/
GMapbookInfo=function(container){
	var parent=container.parentNode;
	var wrapper=document.createElement("div");
	wrapper.style.cssText=container.style.cssText;
	parent.insertBefore(wrapper,container);
	parent.removeChild(container);
	wrapper.appendChild(container);
	container.style.cssText="position: relative; width: 100%; height: 100%;";
	this.backgroundColor="#9999cc";
	this.borderColor="#666699";
	this.overlay=document.createElement("div");
	wrapper.appendChild(this.overlay);
	this.visibleStyle="position: relative; top: -55%; background-color: "+this.backgroundColor+"; width: 40%; text-align: center; margin-left: auto; margin-right: auto; padding: 2em; border: 0.08in ridge "+this.borderColor+"; z-index: 100; opacity: .75; filter: alpha(opacity=75);";
	this.invisibleStyle="display: none;";
	this.overlay.style.cssText=this.invisibleStyle;
};
GMapbookInfo.prototype.show=function(message){
	this.overlay.innerHTML=message;
	this.overlay.style.cssText=this.visibleStyle;
};
GMapbookInfo.prototype.hide=function(){
	this.overlay.style.cssText=this.invisibleStyle;
};
GMapbookInfo.prototype.setBackgroundColor=function(color){
	this.backgroundColor=color;
};
GMapbookInfo.prototype.setBorderColor=function(color){
	this.borderColor=color;
};

/*-------------------------------------------------
全域變數
--------------------------------------------------*/
var container;//地圖容器
var map;//地圖
var geocoder;//地理編碼器，英文版的一個功能，無法使用中文（中文拼音可用）
var posGuest;//訪客位置
var mkGuest;//訪客的地標
var infoTabs=new Array();//所有的資訊視窗，因為為了方便的顯示上一條下一條的消息
var currentPage=1;//當前頁碼
var pagesize=10;//每頁留言條數
var guestIcon;//訪客圖示
var placeIcon;//留言圖示
var sequence=new Array();//標誌留言順序的陣列，
                         //需要這個的原因是同一個視窗中各標籤的發佈時間是不同的
                         //顯示上一條下一條的消息的時候需要考慮顯示第幾個標籤
var currentEntry=0;//當前的留言序號，配合sequence使用
var info;//信息
var mkPlaces=new Array();//地點的陣列GLatLng
var olPlaces=new Array();//地標的陣列GMarker（其實mkPlaces，olPlaces有一個就足夠了）
var logged_in=false;//是否登陸
//幾個按鈕
var btnSubmit;
var btnNextPage;
var btnPreviousPage;
var btnNextMessage;
var btnPreviousMessage;
var btnLog;
var btnRegister;
var btnManage;
var btnGetIt;
/*-------------------------------------------------
各種操作
--------------------------------------------------*/
//檢測縮放以自我調整全屏
function resizeMap(){
	container.style.width=document.body.clientWidth+'px';
	container.style.height=document.body.clientHeight+'px';
	if(map){
		map.checkResize();
	};
};

//初始化，Onload時調用
function init(){
	if(!GBrowserIsCompatible()){
		return;
	};
	container=document.getElementById("mapDiv");
	resizeMap();
	map=new GMap2(container);
	//檢測縮放以自我調整全屏，新版API似乎已經不需要了
	map.checkResize();
	map.setCenter(_home,_zoomlevel);
	info=new GMapbookInfo(map.getContainer());
	guestIcon=new GIcon();
	guestIcon.image="http://labs.google.com/ridefinder/images/mm_20_red.png";
	guestIcon.shadow="http://labs.google.com/ridefinder/images/mm_20_shadow.png";
	guestIcon.iconSize=new GSize(12,20);
	guestIcon.shadowSize=new GSize(22,20);
	guestIcon.iconAnchor=new GPoint(6,20);
	guestIcon.infoWindowAnchor=new GPoint(5,1);
	placeIcon=new GIcon();
	placeIcon.image="http://labs.google.com/ridefinder/images/mm_20_green.png";
	placeIcon.shadow="http://labs.google.com/ridefinder/images/mm_20_shadow.png";
	placeIcon.iconSize=new GSize(12,20);
	placeIcon.shadowSize=new GSize(22,20);
	placeIcon.iconAnchor=new GPoint(6,20);
	placeIcon.infoWindowAnchor=new GPoint(5,1);
	map.checkResize();
	map.setMapType(_maptype);
	map.addControl(new GLargeMapControl());
	map.addControl(new GMapTypeControl());

	//創建按鈕並添加相應事件
	btnSubmit=new GButton(optSubmit);
	btnNextPage=new GButton(optNextPage);
	btnPreviousPage=new GButton(optPreviousPage);
	btnNextMessage=new GButton(optNextMessage);
	btnPreviousMessage=new GButton(optPreviousMessage);
	btnLog=new GButton(optLog);
	btnRegister=new GButton(optRegister);
	btnManage=new GButton(optManage);

	btnSubmit.add(map,function(){
		showWindow(strSubmit);
	}
	);
	btnNextPage.add(map,function(){
		currentEntry=0;
		currentPage--;
		showEntries(true);
	}
	);
	btnPreviousPage.add(map,function(){
		currentEntry=0;
		currentPage++;
		showEntries(true);
	}
	);
	btnNextMessage.add(map,function(){
		showEntry(-1);
	}
	);
	btnPreviousMessage.add(map,function(){
		showEntry(+1);
	}
	);
	btnLog.add(map,function(){
		if(logged_in){
			logout();
		}
		else{
			showWindow(strLogin);
		};
	}
	);
	btnRegister.add(map,function(){
		if(logged_in){
			showWindow(strHelp,"help.html");
		}
		else{
			showWindow(strRegister);
		};
	}
	);
	btnManage.add(map,function(){
		if(logged_in){
			showWindow(tabManage);
		}
		else{
			showWindow(strForgetPassword);
		};
	}
	);

	//動態載入微軟的定位程式
	var s=document.createElement("script");
	s.src="http://local.live.com/WiFiIPService/locate.ashx";
	document.body.appendChild(s);
};

//顯示GInfoWindow
//maxUrl是個未公開的選項，可用於最大化GInfoWindow
function showWindow(action,maximizeURL){
	map.closeInfoWindow();
	if(typeof(action)=="string"){
		mkGuest.openInfoWindowHtml(UpdateStr(action),{
			maxUrl:maximizeURL
		}
		);
	}
	else{
		mkGuest.openInfoWindowTabsHtml(action);
	};
};

//登陸登出顯示切換
function switchLogin(login){
	btnLog.setCaption(arrLog[new Number(login)]);
	btnManage.setCaption(arrManage[new Number(login)]);
	btnRegister.setCaption(arrRegister[new Number(login)]);
};

//無用
function showDownload(){
	showWindow("<table><tr><td style=\"font:14px small-caps; color:#0099FF; text-align:left\">"+strDownload+"</td></tr></table>");
};

//顯示一條留言，change參數用於設置上（下）翻一條等資訊
function showEntry(change){
	if(sequence.length>0){
		currentEntry+=change;
		if(currentEntry<0){
			currentEntry=0;
			info.show(errLoading[3]);
			setTimeout("info.hide();",2000);
			return;
		};
		if(currentEntry>=sequence.length){
			currentEntry=sequence.length-1;
			info.show(errLoading[4]);
			setTimeout("info.hide();",2000);
			return;
		};
		var i=sequence[currentEntry][0];
		mkPlaces[i].openInfoWindowTabsHtml(infoTabs[i],{
			selectedTab:sequence[currentEntry][1]
		}
		);
	};
};

//創建GMarker，根據XML構造留言的文本
//參看ui.php中HTML模版
function createLocationMarker(place,locXML,locId){
	var id;
	var name;
	var email;
	var ip;
	var posttime;
	var replytime;
	var content;
	var reply;
	var rows;
	var entries=locXML.getElementsByTagName("entry");
	if(place.x==posGuest.x&&place.y==posGuest.y){
		mkPlaces[locId]=new GMarker(place,guestIcon);
	}
	else{
		mkPlaces[locId]=new GMarker(place,placeIcon);
	};
	infoTabs[locId]=new Array();
	for(var i=0;i<entries.length;i++){
		var entryHTML=strContent;
		var entry=entries[i];
		sequence[parseInt(entry.getAttribute("sequence"))]=new Array(locId,i);
		id=entry.getAttribute("id");
		name=entry.getAttribute("name");
		email=entry.getAttribute("email");
		ip=entry.getAttribute("ip");
		posttime=entry.getAttribute("posttime");
		replytime=entry.getAttribute("replytime");
		content=entry.getElementsByTagName("content")[0].childNodes[0].nodeValue;
		reply="";
		if(entry.getElementsByTagName("reply")[0].childNodes[0]){
			reply=entry.getElementsByTagName("reply")[0].childNodes[0].nodeValue;
		}
		else{
			replytime="future";
		};
		if(!logged_in){
			if(reply==""){
				rows=_rowcount*2+2;
			}
			else{
				rows=_rowcount;
				entryHTML+=strReply;
			}
			Head=strHead;
			Tail=strTail;
		}
		else{
			Head="<form>"+strHead;
			Tail=strTail+"</form>";
			entryHTML+=strGuestInfo;
			entryHTML+=strReply2;
		};
		entryHTML=Head+entryHTML+Tail;
		entryHTML=entryHTML.replace(/#id#/gim,id);
		entryHTML=entryHTML.replace(/#name#/gim,name);
		entryHTML=entryHTML.replace(/#email#/gim,email);
		entryHTML=entryHTML.replace(/#ip#/gim,ip);
		entryHTML=entryHTML.replace(/#posttime#/gim,posttime);
		entryHTML=entryHTML.replace(/#replytime#/gim,replytime);
		entryHTML=entryHTML.replace(/#content#/gim,content);
		entryHTML=entryHTML.replace(/#reply#/gim,reply);
		entryHTML=entryHTML.replace(/#rowcount#/gim,rows);
		entryHTML=entryHTML.replace(/#admin#/gim,admin);
		entryHTML=entryHTML.replace(/#hidden#/gim,_hiddenMsg);
		infoTabs[locId][i]=new GInfoWindowTab(_tabprefix+" "+(i+1).toString(),entryHTML);
	};
	//監聽點擊
	GEvent.addListener(mkPlaces[locId],"click",function(){
		mkPlaces[locId].openInfoWindowTabsHtml(infoTabs[locId]);
	});
	//添加圖層
	olPlaces[locId]=map.addOverlay(mkPlaces[locId]);
};

//載入留言主函數，載入時調用
//上翻頁下翻頁也利用該函數，popup用於標記是否顯示藍色提示視窗
function showEntries(popup){
	map.closeInfoWindow();
	info.show(operations[0]);
	GDownloadUrl("list.php?uid="+uid+"&page="+currentPage+"&pagesize="+pagesize+"&rand="+Math.random(),function(data){
		var xml=GXml.parse(data);
		//添加已登陸使用者的資訊到Cookie
		logged_in=(xml.documentElement.getAttribute("logged_in")==1);
		var user_info=xml.documentElement.getAttribute("user_info");
		if(user_info!=""){
			addCookie("guestname",user_info.split("|")[0],0);
			addCookie("guestemail",user_info.split("|")[1],0);
		};
		switchLogin(logged_in);
    
		//載入並顯示
		//實現比較醜陋
		var locations=xml.documentElement.getElementsByTagName("location");
		if(locations.length==0){
			if(currentPage==1){
				info.show(errLoading[0]);
				mkPlaces.length=0;
				infoTabs.length=0;
				sequence.length=0;
				setTimeout("info.hide();",2000);
				for(var i=0;i<mkPlaces.length;i++){
					map.removeOverlay(olPlaces[i]);
					mkPlaces[i].remove();
				};
				return;
			}
			else if(currentPage==0){
				currentPage++;
				info.show(errLoading[1]);
				if(popup){
					setTimeout("info.hide(); showEntries(true);",2000);
				}
				else{
					setTimeout("info.hide(); showEntries(false);",2000);
				};
				return;
			}
			else{
				currentPage--;
				info.show(errLoading[2]);
				if(popup){
					setTimeout("info.hide(); showEntries(true);",2000);
				}
				else{
					setTimeout("info.hide(); showEntries(false);",2000);
				};
				return;
			};
		};

		//刪除現有GMarker，以便添加新的
		for(var i=0;i<mkPlaces.length;i++){
			map.removeOverlay(olPlaces[i]);
			mkPlaces[i].remove();
		};
		mkPlaces.length=0;
		olPlaces.length=0;
		infoTabs.length=0;
		sequence.length=0;
		for(var i=0;i<locations.length;i++){
			var place=new GLatLng(parseFloat(locations[i].getAttribute("latitude")),parseFloat(locations[i].getAttribute("longitude")));
			createLocationMarker(place,locations[i],i);
		};
		info.hide();
		if(popup&&locations.length>0){
			showEntry(0);
		};
	}
	);
};

//以下為留言、回復等基本操作，就是利用AJAX發送資料的過程，相當簡單，不再詳細介紹
function post(name,email,code,content,display){
	name=trim(name);
	email=trim(email);
	content=rtrim(content);
	addCookie("guestname",name,0);
	addCookie("guestemail",email,0);
	if((name=="")||(email=="")||(code=="")||(content=="")){
		info.show(errPost[2]);
		setTimeout("info.hide();",2000);
		return;
	};
	var pattern=/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$/;
	if(!pattern.test(email)){
		info.show(errPost[3]);
		setTimeout("info.hide();",2000);
		return;
	};
	var strPost="uid="+uid+"&name="+name+"&email="+email+"&code="+code+"&content="+content+"&longitude="+posGuest.x+"&latitude="+posGuest.y+"&display="+(display?1:0)+"&rand="+Math.random();
	info.show(operations[1]);
	var request=GXmlHttp.create();
	request.open("POST","post.php",true);
	request.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
	request.onreadystatechange=function(){
		if(request.readyState==4){
			var errCode=parseInt(request.responseText);
			info.show(errPost[errCode]);
			if(errCode==0){
				currentPage=1;
				currentEntry=0;
				map.closeInfoWindow();
				setTimeout("showEntries(true);info.hide();",2000);
			}
			else{
				setTimeout("info.hide();changeImg('imgPost');",2000);
			};
		};
	};
	request.send(strPost);
};
function reply(id,content){
	var strPost="uid="+uid+"&id="+id+"&content="+(content)+"&rand="+Math.random();
	info.show(operations[1]);
	var request=GXmlHttp.create();
	request.open("POST","reply.php",true);
	request.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
	request.onreadystatechange=function(){
		if(request.readyState==4){
			var errCode=parseInt(request.responseText);
			info.show(errReply[errCode]);
			if(errCode==0){
				setTimeout("showEntries(true);info.hide();",2000);
			}
			else{
				setTimeout("info.hide();",2000);
			}
		};
	};
	request.send(strPost);
};
function login(email,password,code){
	email=trim(email);
	code=trim(code);
	if((email=="")||(password=="")||(code=="")){
		info.show(errLogin[2]);
		setTimeout("info.hide();",2000);
		return;
	};
	var pattern=/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$/;
	if(!pattern.test(email)){
		info.show(errLogin[3]);
		setTimeout("info.hide();",2000);
		return;
	};
	var strPost="login.php?uid="+uid+"&email="+email+"&passwd="+calcMD5(password)+"&code="+code+"&rand="+Math.random();
	info.show(operations[2]);
	GDownloadUrl(strPost,function(data){
		if(String(data).split("|")[0]=="u"){
			info.show(operations[6]);
			document.location.replace("/?uid="+String(data).split("|")[1]);
			return;
		};
		var errCode=parseInt(data);
		info.show(errLogin[errCode]);
		if(errCode==0){
			currentPage=1;
			currentEntry=0;
			logged_in=true;
			switchLogin(logged_in);
			setTimeout("showEntries(true);info.hide();",2000);
		}
		else{
			setTimeout("info.hide();showWindow(strLogin);",2000);
		}
	}
	);
};

function logout(){
	var strPost="logout.php?uid="+uid+"&rand="+Math.random();
	info.show(operations[3]);
	GDownloadUrl(strPost,function(data){
		var errCode=parseInt(data);
		info.show(errLogout[errCode]);
		if(errCode==0){
			currentPage=1;
			currentEntry=0;
			logged_in=false;
			switchLogin(logged_in);
			setTimeout("showEntries(true);info.hide();",2000);
		}
		else{
			setTimeout("info.hide();",2000);
		};
	}
	);
};
function deleteIt(id){
	var strPost="delete.php?uid="+uid+"&id="+id+"&rand="+Math.random();
	info.show(operations[4]);
	GDownloadUrl(strPost,function(data){
		var errCode=parseInt(data);
		info.show(errDelete[errCode]);
		if(errCode==0){
			currentPage=1;
			currentEntry=0;
			setTimeout("showEntries(true);info.hide();",2000);
		}
		else{
			setTimeout("info.hide();",2000);
		};
	}
	);
};
function setPassword(docreate,email,uname,code){
	email=trim(email);
	code=trim(code);
	if((email=="")||(code=="")||(docreate?(uname==''):false)){
		info.show(errSetPassword[7]);
		setTimeout("info.hide();",2000);
		return;
	};
	var pattern=/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*$/;
	if(!pattern.test(email)){
		info.show(errSetPassword[6]);
		setTimeout("info.hide();",2000);
		return;
	};
	if(docreate){
		var reqtype="resuwen"; //newuser 逆序
	}
	else{
		var reqtype="drowssaptsol";//lostpassword 逆序
	};
	var strPost=encodeURI("sendpassword.php?type="+reqtype+"&email="+email+"&uname="+uname+"&code="+code+"&rand="+Math.random());
	info.show(operations[1]);
	GDownloadUrl(strPost,function(data){
		var errCode=parseInt(data);
		info.show(errSetPassword[errCode]);
		setTimeout("info.hide();map.closeInfoWindow();",2000);
	}
	);
};
function updatePassword(oldpass,newpass,newpass2){
	if((oldpass=="")||(newpass=="")||(newpass2=="")){
		info.show(errUpdatePassword[1]);
		setTimeout("info.hide();",2000);
		return;
	};
	if(newpass!=newpass2){
		info.show(errUpdatePassword[2]);
		setTimeout("info.hide();",2000);
		return;
	};
	var strPost="updatepassword.php?uid="+uid+"&oldpass="+calcMD5(oldpass)+"&newpass="+calcMD5(newpass)+"&rand="+Math.random();
	info.show(operations[1]);
	GDownloadUrl(strPost,function(data){
		var errCode=parseInt(data);
		info.show(errUpdatePassword[errCode]);
		setTimeout("info.hide();",2000);
	}
	);
};
function updateSettings(mapConfig,emailAlert){
	var zl=mapConfig?map.getZoom():2;
	var ll=mapConfig?map.getCenter().toUrlValue():"30.58, 114.27";
	var mt=mapConfig?_maptypes.indexOf(map.getCurrentMapType()):0;
	var config=zl+"|"+ll+"|"+mt+"|"+emailAlert;
	var strPost="updatesettings.php?uid="+uid+"&cfg="+config+"&rand="+Math.random();
	info.show(operations[1]);
	GDownloadUrl(strPost,function(data){
		var errCode=parseInt(data);
		info.show(errUpdateSettings[errCode]);
		setTimeout("info.hide();",2000);
	}
	);
}

//利用地理編碼定位，大陸無資訊，因此未使用
function locate(address){
	geocoder=new GClientGeocoder();
	geocoder.getLatLng(address,function(point){
		if(!point){
			alert(address+" not found");
		}
		else{
			posGuest=point;
			mkGuest.setPoint(posGuest);
			showWindow(strSubmit);
		};
	}
	);
};

//更新驗證碼
function changeImg(id){
	if((typeof(id)=="string")&&document.getElementById(id)){
		document.getElementById(id).src="verify.php?rand="+Math.random();
	}
	else{
		id.src="verify.php?rand="+Math.random();
	};
};
function UpdateStr(src){
	return src.replace("#verify#","verify.php?rand="+Math.random()).replace("#guestname#",getCookie("guestname")).replace("#guestemail#",getCookie("guestemail"));
};
function showGuest(lat,lng){
	posGuest=new GLatLng(lat,lng);
	mkGuest=new GMarker(posGuest,guestIcon);
	map.addOverlay(mkGuest);
	showEntries(true);
}


/*-------------------------------------------------
微軟定位的介面
SetAutoLocateViewport出現為成功
否則為失敗，這樣就調用候選的GEOIP資料
--------------------------------------------------*/
function SetAutoLocateViewport(lat,lng,zoom,b,s){
	showGuest(lat,lng);
};
function ShowMessage(message){
	showGuest(geoip_latitude(),geoip_longitude());
};
function AutoLocateUndetectable(message){
	showGuest(geoip_latitude(),geoip_longitude());
};

/*-------------------------------------------------
Cookie操作
以下還不夠嚴謹
--------------------------------------------------*/
function addCookie(name,value,expireHours){
	var cookieString=name+"="+escape(value);
	if(expireHours>0){
		var date=new Date();
		date.setTime(date.getTime+expireHours*3600*1000);
		cookieString=cookieString+"; expire="+date.toGMTString();
	}
	document.cookie=cookieString;
}
function getCookie(name){
	var strCookie=document.cookie;
	var arrCookie=strCookie.split("; ");
	for(var i=0;i<arrCookie.length;i++){
		var arr=arrCookie[i].split("=");
		if(arr[0]==name)return unescape(arr[1]);
	}
	return "";
}
function deleteCookie(name){
	var date=new Date();
	date.setTime(date.getTime()-10000);
	document.cookie=name+"=v; expire="+date.toGMTString();
}

/*-------------------------------------------------
trim
這個完全可以用RegEx完成
--------------------------------------------------*/
function ltrim(str){
	var whitespace=new String(" \t\n\r");
	var s=new String(str);
	if(whitespace.indexOf(s.charAt(0))!=-1){
		var j=0,i=s.length;
		while(j<i&&whitespace.indexOf(s.charAt(j))!=-1){
			j++;
		};
		s=s.substring(j,i);
	};
	return s;
};
function rtrim(str){
	var whitespace=new String(" \t\n\r");
	var s=new String(str);
	if(whitespace.indexOf(s.charAt(s.length-1))!=-1){
		var i=s.length-1;
		while(i>=0&&whitespace.indexOf(s.charAt(i))!=-1){
			i--;
		};
		s=s.substring(0,i+1);
	};
	return s;
};
function trim(str){
	return rtrim(ltrim(str));
};
