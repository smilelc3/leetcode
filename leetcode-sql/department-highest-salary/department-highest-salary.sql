# 初始化
create database if not exists leetcode;

drop table if exists Employee;
create table Employee
(
    Id           int,
    Name         varchar(255),
    Salary       int,
    DepartmentId int
);
drop table if exists Department;
create table if not exists Department
(
    Id   int,
    Name varchar(255)
);

truncate table Employee;

insert into Employee (Id, Name, Salary, DepartmentId)
values ('1', 'Joe', '70000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('2', 'Jim', '90000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('3', 'Henry', '80000', '2');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('4', 'Sam', '60000', '2');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('5', 'Max', '90000', '1');

Truncate table Department;

insert into Department (Id, Name)
values ('1', 'IT');

insert into Department (Id, Name)
values ('2', 'Sales');

# 查询部门最高工资
select Department.Name as Department, Employee.Name as Employee, Salary
from Department
         left join Employee on Department.Id = Employee.DepartmentId
where (Department.Id, Salary) in (
    select DepartmentId, max(Salary)
    from Employee
    group by DepartmentId
);