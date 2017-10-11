create database asp;


create table user (
    username varchar(16)  NOT NULL PRIMARY KEY,
    salt varchar(16) NOT NULL,
    password varchar(32) NOT NULL,
    image_path varchar(1024),
	hands_won int,
    hands_played int,
    chip_count bigint,
    last_login datetime,
    
);

create table user_friend (
    username varchar(16),
	friend varchar(16)
);

create table user_statistic (
	username varchar(16),

);




insert into user values ('tester', '1','password');

select * from user;
