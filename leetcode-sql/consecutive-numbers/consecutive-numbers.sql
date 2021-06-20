create database if not exists leetcode;
use leetcode;
drop table if exists Logs;

Create table Logs
(
    Id  int,
    Num int
);

insert into Logs (Id, Num)
values ('1', '1');
insert into Logs (Id, Num)
values ('2', '1');
insert into Logs (Id, Num)
values ('3', '1');
insert into Logs (Id, Num)
values ('4', '2');
insert into Logs (Id, Num)
values ('5', '1');
insert into Logs (Id, Num)
values ('6', '2');
insert into Logs (Id, Num)
values ('7', '2');


# 查询连续出现3次以上的Num(lag函数：下一个)
with lag_logs as (select Num,
                         lag(Num, 1) over ()  as lag_1_num,
                         lag(Num, 2) over () as lag_2_num
                  from Logs)
select distinct Num as ConsecutiveNums
from lag_logs
where Num = lag_1_num and lag_1_num = lag_2_num;


# 查询连续出现3次以上的Num(lead函数：上一个)
with lag_logs as (select Num,
                         lead(Num, 1) over ()  as lead_1_num,
                         lead(Num, 2) over () as lead_2_num
                  from Logs)
select distinct Num as ConsecutiveNums
from lag_logs
where lead_2_num = lead_1_num and lead_1_num = Num;

