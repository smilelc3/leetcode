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

set global log_bin_trust_function_creators = 1;
drop function if exists getNthHighestSalary;

# 创建函数：查询第N高的工资
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    RETURN (
        with rank_Employee as (select Salary, dense_rank() over (order by Salary desc) as salary_rank from Employee)
        select distinct Salary
        from rank_Employee
        where salary_rank = N
    );
END;

# 查询第1高的工资
select getNthHighestSalary(1);

# 查询第3高的工资
select getNthHighestSalary(3);