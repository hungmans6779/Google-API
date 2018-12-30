-- phpMyAdmin SQL Dump
-- version 2.10.0.2
-- http://www.phpmyadmin.net
--
-- 主機: localhost
-- 生成日期: 2007 年 05 月 15 日 09:59
-- 伺服器版本: 5.0.27
-- PHP 版本: 4.4.4

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- 資料庫: `guestbook`
--

-- --------------------------------------------------------

--
-- 表的結構 `messages`
--

CREATE TABLE `messages` (
  `id` int(11) NOT NULL auto_increment,
  `uid` int(11) NOT NULL default '0',
  `name` varchar(20) NOT NULL default '',
  `email` varchar(150) NOT NULL default '',
  `content` text NOT NULL,
  `reply` text,
  `ip` int(11) NOT NULL default '-1',
  `longitude` decimal(11,8) NOT NULL default '0.00000000',
  `latitude` decimal(11,8) NOT NULL default '0.00000000',
  `posttime` datetime NOT NULL default '0000-00-00 00:00:00',
  `replytime` datetime default NULL,
  `display` tinyint(1) NOT NULL default '1',
  PRIMARY KEY  (`id`),
  KEY `display` (`display`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 表的結構 `users`
--

CREATE TABLE `users` (
  `uid` int(11) NOT NULL auto_increment,
  `uname` varchar(20) NOT NULL default '',
  `upass` varchar(32) NOT NULL default '',
  `upass2` varchar(32) NOT NULL default '',
  `email` varchar(50) NOT NULL default '',
  `regtime` datetime NOT NULL default '0000-00-00 00:00:00',
  `lastlogin` datetime default NULL,
  `activated` tinyint(1) NOT NULL default '0',
  `settings` varchar(90) NOT NULL default '2|30.58, 114.27|0|true',
  PRIMARY KEY  (`uid`),
  UNIQUE KEY `email` (`email`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- 必須手動插入第一個使用者admin，密碼abc，以後可以修改
-- 尚在測試，不完善
--

INSERT INTO `users` VALUES (1, 'admin', '900150983CD24FB0D6963F7D28E17F72', '900150983CD24FB0D6963F7D28E17F72', 'admin@example.com', '2007-03-16 00:00:00', '2007-05-16 01:15:43', 1, '6|32.639375,114.257813|0|false');
