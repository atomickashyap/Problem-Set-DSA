# Write your MySQL query statement below
select u.unique_id as unique_id, e.name as name from Employees as e left join EmployeeUNI as u on e.id = u.id;


# select u.unique_id as unique_id, n.name as name
# from Employees n left join EmployeeUNI u on n.id=u.id