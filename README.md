diasoft test task

# Задание 1
```sql
select distinct d.Name
from Departments as d left join Employee as e on d.Id = e.ExtidDepartments
group by d.Name having count(*) < 5
```

# Задание 3
требует предустановленных curl и nlohmann-json