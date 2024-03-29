# Write your MySQL query statement below
select p.product_id, s.year as first_year, s.quantity as quantity, s.price from Product p
left join Sales s on p.product_id = s.product_id
where (s.product_id, s.year) in (select s1.product_id, min(s1.year) from Sales s1 group by s1.product_id)
