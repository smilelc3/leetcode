# 初始化
create database if not exists leetcode;
use leetcode;

drop table if exists Employee;
Create table Employee
(
    Id     int,
    Salary int
);
Truncate table Employee;
insert into Employee (Id, Salary)
values ('1', '100');
insert into Employee (Id, Salary)
values ('2', '200');
insert into Employee (Id, Salary)
values ('3', '300');

# 显示第二高的工资，若没有，显示null
select max(Salary) as SecondHighestSalary
from Employee
where Salary < (select max(Salary) from Employee);


