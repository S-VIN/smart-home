module github.com/S-VIN/smart-home/tree/master

go 1.16

require (
	github.com/S-VIN/smart-home/tree/master/pkg/connectors v0.0.0
	github.com/S-VIN/smart-home/tree/master/pkg/utils v0.0.0 // indirect
	github.com/jackc/pgx/v4 v4.13.0
)

replace github.com/S-VIN/smart-home/tree/master/pkg/connectors v0.0.0 => /home/stepan/Yandex.Disk/Documents/homeProjects/smart-home/pkg/connectors

replace github.com/S-VIN/smart-home/tree/master/pkg/utils v0.0.0 => /home/stepan/Yandex.Disk/Documents/homeProjects/smart-home/pkg/utils
