package main

import (
	con "github.com/S-VIN/smart-home/tree/master/pkg/connectors"
)

func main() {
	//var orm Orm
	//err := orm.Init("user=postgres password=3228 host=localhost port=5432 dbname=smarthome sslmode=verify-ca")

	//for i := 1; i <= 10; i++ {
	//	fmt.Print(i, " ")
	//	fmt.Println(orm.GetStateByDeviceId(Id(i)))
	//}
	//
	//if(err != nil){
	//	fmt.Println(err)
	//}

	//conn.Init()

	con.NewConnection(":1111")



}

