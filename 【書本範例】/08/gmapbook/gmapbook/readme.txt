使用方法
1. include/config.inc.php為設定檔，使用前請按注釋提示編輯
需要修改的部分
資料庫主機  $_DBHOST 通常為localhost
資料庫使用者  $_DBUSER
資料庫名    $_DBNAME
資料庫密碼  $_DBPASS

GMail帳號   $_MAILACCT   (無 @gmail.com， 如test@gmail.com，只需填寫test即可)
GMail密碼   $_MAILPASS

若未配置GMail帳號資訊，則會導致註冊失敗

2. 在本地新建一個MySql資料庫，資料庫名應和步驟 1 中$_DBNAME保持一致
3. 將install.sql導入資料庫（預設插入第一個使用者admin，密碼abc，登陸郵箱admin@example.com）
如果需要進行修改，請直接修改install.sql中的下面這一毅句
INSERT INTO `users` VALUES (1, 'admin', '900150983CD24FB0D6963F7D28E17F72', '900150983CD24FB0D6963F7D28E17F72', 'admin@example.com', '2007-03-16 00:00:00', '2007-05-16 01:15:43', 1, '6|32.639375,114.257813|0|false');


注意事項
1. 所有操作為了減少流量，只返回Error Number，相應含義見ui.php
2. 請勿在localhost或局域網內調試，本地IP將導致無法取得正確的地理位置

文件列表
GMAPBOOK
│  api.zh-cn.js	中文Google Maps API，不是最新版，僅作參考
│  background1.jpg	驗證碼背景
│  background2.jpg	驗證碼背景
│  background3.jpg	驗證碼背景
│  delete.php		刪除留言
│  favicon.ico		網站圖示
│  gmapbook.zh-cn.js	核心功能（壓縮）
│  help.html		未完成的幫助
│  index.php		首頁
│  list.php		XML格式留言的列表（含分頁等功能，需要PHP5以上版本XMLDOM支援，當然如果改成直接用echo輸出，則可用於較低的PHP版本）
│  login.php		驗證登陸
│  logout.php		登出
│  post.php		提交留言
│  reply.php		回復留言
│  sendpassword.php	發送密碼（註冊和取回密碼）
│  ui.php		用於設置介面的Javascript，部分資料從資料庫中取出
│  updatepassword.php	更改密碼
│  updatesettings.php	更新設置（不完善）
│  verify.php		驗證碼（簡單）
│
└─include
    │  class.mysqldb.php		mysql類
    │  class.securesession.php		session類
    │  config.inc.php			設定檔，需編輯
    │  include.inc.php			包含檔
    │
    └─phpmailer			以下為郵件發送類（經本人修改過的PHPMailer，完美支援GMail，使用方法上和原始PHPMailer無區別）
        │  ChangeLog.txt
        │  class.phpmailer.php
        │  class.smtp.php
        │  LICENSE
        │  README
        │
        ├─docs
        │      extending.html
        │      faq.html
        │      timeoutfix.diff
        │
        ├─language
        │      phpmailer.lang-br.php
        │      phpmailer.lang-ca.php
        │      phpmailer.lang-cz.php
        │      phpmailer.lang-de.php
        │      phpmailer.lang-dk.php
        │      phpmailer.lang-en.php
        │      phpmailer.lang-es.php
        │      phpmailer.lang-fi.php
        │      phpmailer.lang-fo.php
        │      phpmailer.lang-fr.php
        │      phpmailer.lang-hu.php
        │      phpmailer.lang-it.php
        │      phpmailer.lang-ja.php
        │      phpmailer.lang-nl.php
        │      phpmailer.lang-no.php
        │      phpmailer.lang-pl.php
        │      phpmailer.lang-ro.php
        │      phpmailer.lang-ru.php
        │      phpmailer.lang-se.php
        │      phpmailer.lang-tr.php
        │
        ├─phpdoc
        │  │  blank.html
        │  │  classtrees_PHPMailer.html
        │  │  elementindex.html
        │  │  elementindex_PHPMailer.html
        │  │  errors.html
        │  │  index.html
        │  │  li_PHPMailer.html
        │  │  packages.html
        │  │
        │  ├─media
        │  │      banner.css
        │  │      stylesheet.css
        │  │
        │  └─PHPMailer
        │          PHPMailer.html
        │          SMTP.html
        │          _class_phpmailer_php.html
        │          _class_smtp_php.html
        │
        └─test
                phpmailer_test.php
                phpunit.php
                test.png

