# 初始化
create database if not exists leetcode;
use leetcode;

drop table if exists Employee;
Create table Employee
(
    Id        int,
    Name      varchar(255),
    Salary    int,
    ManagerId int
);
Truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId)
values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId)
values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId)
values ('3', 'Sam', '60000', NULL);
insert into Employee (Id, Name, Salary, ManagerId)
values ('4', 'Max', '90000', NULL);


# 查询比主管工资更高的职员
select Employee.Name as Employee
from Employee
    inner join Employee as Manager on Employee.ManagerId = Manager.Id
where Employee.Salary > Manager.Salary;