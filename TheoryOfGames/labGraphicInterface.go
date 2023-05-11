package main

import (
	"errors"
	"fmt"
	"strconv"
	"strings"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/dialog"
	"fyne.io/fyne/v2/widget"
)

func deleteDominantStrategyAR(res *widget.Label, matrix [][]int) { // ([][]int, bool) {

	//isstrogo := false

	strogo := false
	wasdel := false
	for i := len(matrix) - 1; i >= (0 + 1); i-- {
		strogo = true
		for j := len(matrix[i]) - 1; j >= 0; j-- {

			if strogo == true {
				if matrix[i][j] <= matrix[i-1][j] {

					strogo = false
					break
				}
			} else {
				break

			}
		}
		if strogo {
			matrix = deleteRowR(matrix, i-1)
			res.SetText(res.Text + "Была удалена строго доминируемая стратегия для А " + strconv.Itoa(i) + "\n")
			wasdel = true
		}
	}

	for i := 0; i < (len(matrix) - 1); i++ {
		strogo = true

		for j := 0; j < len(matrix[i]); j++ {

			if strogo == true {

				if matrix[i][j] <= matrix[i+1][j] {

					strogo = false
					break
				}
			} else {
				break
			}
		}

		if strogo {

			matrix = deleteRowR(matrix, i+1)
			res.SetText(res.Text + "Была удалена строго доминируемая стратегия для А " + strconv.Itoa(i+2) + "\n")
			wasdel = true
		}

	}
	if wasdel {
		for i := range matrix {
			for _, val := range matrix[i] {
				res.SetText(res.Text + strconv.Itoa(val))
			}
			res.SetText(res.Text + "\n")
		}
	} else {
		res.SetText(res.Text + "Не было найдено строго доминирующей стратегии для А игрока\n")
	}

}

func deleteDominantStrategyBR(res *widget.Label, matrix [][]int) { // ([][]int, bool) {

	//isstrogo := false
	strogo := false
	wasdel := false

	for j := len(matrix[0]) - 1; j >= 1; j-- {

		strogo = true
		for i := len(matrix) - 1; i >= 0; i-- {

			if strogo == true {

				if matrix[i][j] <= matrix[i][j-1] {

					strogo = false
					break
				}
			} else {
				break

			}
		}
		if strogo {

			matrix = deleteColumnR(matrix, j-1)
			res.SetText(res.Text + "Была удалена строго доминируемая стратегия для В " + strconv.Itoa(j) + "\n")
			wasdel = true
		}
	}

	for j := 0; j < len(matrix[0])-1; j++ {

		strogo = true

		for i := 0; i < (len(matrix)); i++ {

			if strogo == true {

				if matrix[i][j] <= matrix[i][j+1] {

					strogo = false
					break
				}
			} else {
				break
			}
		}

		if strogo {

			matrix = deleteColumnR(matrix, j+1)

			res.SetText(res.Text + "Была удалена строго доминируемая стратегия для В " + strconv.Itoa(j+2) + "\n")
			wasdel = true
		}

	}
	if wasdel {
		for i := range matrix {
			for _, val := range matrix[i] {
				res.SetText(res.Text + strconv.Itoa(val))
			}
			res.SetText(res.Text + "\n")
		}
	} else {
		res.SetText(res.Text + "Не было найдено строго доминирующей стратегии для B игрока\n")
	}

}

func deleteRowR(matrix [][]int, row int) [][]int {
	matrix = append(matrix[:row], matrix[row+1:]...)
	return matrix
}

func deleteColumnR(matrix [][]int, col int) [][]int {
	for i := 0; i < len(matrix); i++ {
		matrix[i] = append(matrix[i][:col], matrix[i][col+1:]...)
	}
	return matrix
}

func MMR(res *widget.Label, matrix [][]int) (int, int) {

	var masmin, masmax []int

	var max, min int

	for i := 0; i < len(matrix); i++ {
		min = matrix[i][0]

		for j := 0; j < len(matrix[i]); j++ {

			if matrix[i][j] < min {

				min = matrix[i][j]
			}

		}
		masmin = append(masmin, min)

	}

	for j := 0; j < len(matrix[0]); j++ {
		max = matrix[0][j]

		for i := 0; i < len(matrix); i++ {

			if matrix[i][j] > max {

				max = matrix[i][j]
			}

		}
		masmax = append(masmax, max)

	}

	if len(masmin) > 0 {
		max = masmin[0]
		for _, val := range masmin {
			if val > max {
				max = val
			}

		}
	} else {
		res.SetText(res.Text + "Массив masmin пустой\n")
	}

	if len(masmax) > 0 {
		min = masmax[0]
		for _, val := range masmax {
			if val < min {
				min = val
			}

		}
	} else {
		res.SetText(res.Text + "Массив masmax пустой\n")
	}

	return min, max
}

func readMatrR(input string, sizeX int, sizeY int) ([][]int, error) {
	// Создаем матрицу нужного размера
	rows := strings.Split(strings.TrimSpace(input), "\n")
	matrix := make([][]int, len(rows))

	for i, row := range rows {
		values := strings.Split(row, " ")
		rowValues := make([]int, len(values))

		for j, val := range values {
			num, err := strconv.Atoi(val)
			if err != nil {
				return nil, err
			}
			rowValues[j] = num
		}
		matrix[i] = rowValues
	}
	return matrix, nil // Возврат матрицы
}
func main() {

	a := app.New()

	w := a.NewWindow("Teory of games")
	w.Resize(fyne.NewSize(400, 600))

	ic, _ := fyne.LoadResourceFromPath("icon.jpg")
	w.SetIcon(ic)

	label := widget.NewLabel("Введите размеры модели")
	label1 := widget.NewLabel("Введите модель")
	label1.Hide()
	label2 := widget.NewLabel("Выберите тип модели")

	res := widget.NewLabel("")

	sizeX := widget.NewEntry()
	sizeX.SetPlaceHolder("X")
	sizeY := widget.NewEntry()
	sizeY.SetPlaceHolder("Y")
	var sY, sX int

	box := container.NewHBox(sizeX, sizeY)

	entry1 := widget.NewMultiLineEntry()
	entry1.Wrapping = fyne.TextWrapBreak
	entry1.SetPlaceHolder("Матрица А")
	entry1.Hide()
	entry2 := widget.NewMultiLineEntry()
	entry2.Wrapping = fyne.TextWrapBreak
	entry2.SetPlaceHolder("Матрица В")
	entry2.Hide()

	var bimatrix bool
	typeSys := widget.NewRadioGroup([]string{"Матричная", "Биматричная"}, func(s string) {

	})

	btn1 := widget.NewButton("Посчитать максимин/минимакс", func() {

		matrix, err := readMatrR(entry1.Text, sX, sY)
		if err != nil {
			fmt.Println(err)
		}

		for i := range matrix {
			for _, num := range matrix[i] {

				b := strconv.Itoa(num)
				res.SetText(res.Text + b + " ")

			}
			res.SetText(res.Text + "\n")
		}

		minimax, maximin := MMR(res, matrix)

		res.SetText(res.Text + "MINIMAX==" + strconv.Itoa(minimax) + "  MAXIMIN==" + strconv.Itoa(maximin) + "\n")

	})
	btn1.Hide()

	btn2 := widget.NewButton("Удаление строго доминируемых стратегий", func() {

		matrix1, err := readMatrR(entry1.Text, sX, sY)
		if err != nil {
			fmt.Println(err)
		}
		matrix2, err := readMatrR(entry2.Text, sX, sY)
		if err != nil {
			fmt.Println(err)
		}
		res.SetText(res.Text + "Матрица А\n")
		for i := range matrix1 {
			for _, num := range matrix1[i] {

				b := strconv.Itoa(num)
				res.SetText(res.Text + b + " ")

			}
			res.SetText(res.Text + "\n")
		}

		res.SetText(res.Text + "Матрица B\n")
		for i := range matrix2 {
			for _, num := range matrix2[i] {

				b := strconv.Itoa(num)
				res.SetText(res.Text + b + " ")

			}
			res.SetText(res.Text + "\n")
		}

		deleteDominantStrategyAR(res, matrix1)
		deleteDominantStrategyBR(res, matrix2)

	})
	btn2.Hide()

	btn := widget.NewButton("Ввод параметров", func() {
		var err bool
		var errx, erry error
		if typeSys.Selected == "Биматричная" {
			bimatrix = true
			err = false
		} else if typeSys.Selected == "" {
			dialog.ShowError(
				errors.New("Не выбран тип системы!!!"),
				w)
			err = true
		} else if typeSys.Selected == "Матричная" {
			bimatrix = false
			err = false
		}
		sX, errx = strconv.Atoi(sizeX.Text)
		if errx != nil {
			dialog.ShowError(
				errors.New("Неправльно введено Х!!!"),
				w)
			err = true
		}
		sY, erry = strconv.Atoi(sizeY.Text)
		if erry != nil {
			dialog.ShowError(
				errors.New("Неправльно введено У!!!"),
				w)
			err = true
		}
		if sX == 1 || sY == 1 {
			dialog.ShowError(
				errors.New("Введите значения Х и У > 1!!!"),
				w)
			err = true

		}

		if !err && bimatrix {
			btn2.Show()
			btn1.Hide()
			entry1.Show()
			entry2.Show()
		} else if !err && !bimatrix {
			btn1.Show()
			btn2.Hide()
			entry1.Show()
			entry2.Hide()
		} else {
			btn1.Hide()
			btn2.Hide()
			entry1.Hide()
			entry2.Hide()
		}

	})

	w.SetContent(

		container.NewVBox(
			label,
			box,
			label2,
			typeSys,
			label1,

			btn,
			entry1,
			entry2,
			btn1,
			btn2,
			res,
		))

	w.ShowAndRun()

}
