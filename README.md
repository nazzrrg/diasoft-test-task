diasoft test task

# Задание 1
'''
select distinct d.Name
from Departments as d left join Employee as e on d.Id = e.ExtidDepartments
group by d.Name having count(*) < 5
'''