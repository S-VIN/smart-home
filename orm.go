package main

import (
	"context"
	"github.com/jackc/pgx/v4"
)

type Id uint64

type State struct {
	Id Id `json:"id_device"`
	Name string `json:"name_of_device"`
	State bool `json:"state"`
}

type Orm struct {
	conn *pgx.Conn
}

func (orm *Orm) Init(connectionString string) (err error){
	if(connectionString == ""){
		connectionString = "user=postgres password=3228 host=localhost port=5432 dbname=smarthome sslmode=verify-ca"
	}
	config, _ := pgx.ParseConfig(connectionString)
	orm.conn, err = pgx.ConnectConfig(context.Background(), config)
	return err;
}

func (orm *Orm) GetStateByDeviceId(id Id) (state bool, err error){
	var nameTemp string
	var idTemp int

	err = orm.conn.QueryRow(context.Background(), "SELECT * FROM statesdb WHERE id_device=$1", int(id)).Scan(&idTemp, &nameTemp, &state)
	if err!=nil {
		return false, err
	}
	return
}

func (orm *Orm) Close(){
	orm.conn.Close(context.Background())
}


//func main() {
//
//
//	rows, err := conn.Query(context.Background(), "select * from statesdb")
//	for rows.Next() {
//		rows.Scan(&states.Id, &states.Name, &states.State)
//		fmt.Println(states)
//	}
//	if err != nil {
//		fmt.Fprintf(os.Stderr, "QueryRow failed: %v\n", err)
//		os.Exit(1)
//	}
//
//}
