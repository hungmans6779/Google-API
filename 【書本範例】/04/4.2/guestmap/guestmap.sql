-- guestmap.sql
-- 創建數據庫: `guestmap`
CREATE DATABASE ` guestmap ` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
-- 如無法創建數據庫，可以使用已有的數據庫

-- --------------------------------------------------------

-- 創建數據表`guestinfo`
CREATE TABLE `guestinfo` (
  `id` int(11) NOT NULL auto_increment COMMENT 'id',
  `ip` int(11) NOT NULL COMMENT '訪客IP',
  `time` timestamp NOT NULL default CURRENT_TIMESTAMP COMMENT '訪問時間 ',
  `lat` double NOT NULL COMMENT '緯度',
  `lng` double NOT NULL COMMENT '經度',
  `city` varchar(255) NOT NULL COMMENT '訪客所在城市（鎮等）',
  `region` varchar(255) NOT NULL COMMENT '訪客所在州（省、自治區、直轄市等）',
  `country` varchar(255) NOT NULL COMMENT '訪客所在國家（或地區）',
  `ua` varchar(255) NOT NULL COMMENT '瀏覽器UA',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='訪客信息表 ' AUTO_INCREMENT=1 ;
