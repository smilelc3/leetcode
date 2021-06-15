# 初始化
create database if not exists leetcode;
use leetcode;
drop table if exists Customers;
Create table Customers
(
    Id   int,
    Name varchar(255)
);
drop table if exists Orders;
Create table Orders
(
    Id         int,
    CustomerId int
);
Truncate table Customers;
insert into Customers (Id, Name)
values ('1', 'Joe');
insert into Customers (Id, Name)
values ('2', 'Henry');
insert into Customers (Id, Name)
values ('3', 'Sam');
insert into Customers (Id, Name)
values ('4', 'Max');
Truncate table Orders;
insert into Orders (Id, CustomerId)
values ('1', '3');
insert into Orders (Id, CustomerId)
values ('2', '1');

# 查询从不订购任何东西的所有客户 (左连接不包含内连接)
select Customers.Name as Customers
from Customers
         left join Orders on Orders.CustomerId = Customers.Id
where Orders.Id is null;

# 查询从不订购任何东西的所有客户 (not in)
select Customers.Name as Customers
from Customers
where Customers.Id not in (select distinct CustomerId from Orders);