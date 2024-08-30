# Write your MySQL query statement below
select p.product_name product_name, sum(o.unit) unit from 
Products p
left join Orders o
on p.product_id = o.product_id
where extract(month from o.order_date) = '02'  and  YEAR(o.order_date)='2020'
group by p.product_name
having sum(o.unit)>= 100