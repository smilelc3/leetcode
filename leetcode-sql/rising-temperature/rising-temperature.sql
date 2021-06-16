# 初始化
create database if not exists leetcode;
use leetcode;

drop table if exists Weather;
Create table Weather
(
    Id          int,
    RecordDate  date,
    Temperature int
);
Truncate table Weather;
insert into Weather (Id, RecordDate, Temperature)
values ('1', '2015-01-01', '10');
insert into Weather (Id, RecordDate, Temperature)
values ('2', '2015-01-02', '25');
insert into Weather (Id, RecordDate, Temperature)
values ('3', '2015-01-03', '20');
insert into Weather (Id, RecordDate, Temperature)
values ('4', '2015-01-04', '30');

# 查询所有比昨天天气高的所有天气ID
select today.Id as Id
from Weather as today
         inner join Weather as yesterday on today.RecordDate = date_add(yesterday.RecordDate, interval 1 day)
where today.Temperature > yesterday.Temperature;