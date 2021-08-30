package test

import (
	"fmt"
	"testing"
)

func TestSum(t *testing.T){
	if sum(1, 2) != 3 {
        t.Fatalf("error")
    }
}
