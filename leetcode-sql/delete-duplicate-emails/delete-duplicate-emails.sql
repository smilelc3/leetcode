# 初始化
create database if not exists leetcode;
use leetcode;

drop table if exists Person;
create table Person
(
    Id    int          null,
    Email varchar(255) null
);
insert into Person (Id, Email)
values ('1', 'john@example.com');
insert into Person (Id, Email)
values ('2', 'bob@example.com');
insert into Person (Id, Email)
values ('3', 'john@example.com');


# 删除重复元素(group by)
delete
from Person
where Id not in (
    select *
    from (select min(Id)
          from Person
          group by Email) as temp
);

# 删除重复元素(rank())
delete
from Person
where Id in (
    select Id
    from (select Id, rank() over (partition by Email order by Id) as id_rank
          from Person) as temp
    where temp.id_rank > 1
);

# 删除重复元素(with+rank())
with cte as
         (select Id, rank() over (partition by email order by Id) as id_rank
          from Person)
delete
from Person
where Id in (select Id from cte where id_rank > 1);


# 查看删除结果
select *
from Person;

