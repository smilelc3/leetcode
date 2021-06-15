# 初始化
create database if not exists leetcode;
use leetcode;

create table if not exists Employee
(
    Id           int,
    Name         varchar(255),
    Salary       int,
    DepartmentId int
);

create table if not exists Department
(
    Id   int,
    Name varchar(255)
);

truncate table Employee;

insert into Employee (Id, Name, Salary, DepartmentId)
values ('1', 'Joe', '85000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('2', 'Henry', '80000', '2');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('3', 'Sam', '60000', '2');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('4', 'Max', '90000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('5', 'Janet', '69000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('6', 'Randy', '85000', '1');

insert into Employee (Id, Name, Salary, DepartmentId)
values ('7', 'Will', '70000', '1');

Truncate table Department;

insert into Department (Id, Name)
values ('1', 'IT');

insert into Department (Id, Name)
values ('2', 'Sales');

# 查询部门最高前三工资（左连接+子查询）
select Department.Name as Department, Employee.Name as Employee, Salary
from Employee
         left join Department on Department.Id = Employee.DepartmentId
where (
          select count(distinct e2.Salary)
          from Employee e2
          where e2.Salary > Employee.Salary
            and e2.DepartmentId = Employee.DepartmentId
      ) < 3;
# 比某人多的工资人数小于3人时，代表这个是就是前3


# 查询部门最高前三工资（窗口函数: dense_rank()）
select Department, Employee, Salary
from (
         select Department.Name                                                             as Department,
                Employee.Name                                                               as Employee,
                Salary,
                dense_rank() over (partition by Employee.DepartmentId order by Salary desc) as ranking
         from Employee
                  join Department on Department.Id = Employee.DepartmentId) as temp
where ranking <= 3;


