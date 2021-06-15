# 初始化
create database if not exists leetcode;
use leetcode;
drop table if exists Person;
Create table Person
(
    Id    int,
    Email varchar(255)
);
Truncate table Person;
insert into Person (Id, Email)
values ('1', 'a@b.com');
insert into Person (Id, Email)
values ('2', 'c@d.com');
insert into Person (Id, Email)
values ('3', 'a@b.com');

# 查找重复元素
select Email
from Person
group by Email
having count(Email) > 1;