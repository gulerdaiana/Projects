Sub MergeCells()
    Dim ws As Worksheet
    Set ws = ThisWorkbook.Worksheets("Sheet1")
    ws.Range("A1:D1").Merge
    ws.Cells.EntireColumn.AutoFit
    ws.Cells.EntireRow.AutoFit
    With ws.UsedRange.Borders
        .LineStyle = xlContinuous
        .Weight = xlThin
    End With
    ws.Cells(3, "G").EntireColumn.AutoFit
    
    ws.Columns("B:B").ColumnWidth = 25
    
    ws.Columns("B:B").WrapText = True
    
    With ws.Sort
        .SortFields.Clear
        .SortFields.Add Key:=ws.Range("D3:D" & ws.Cells(ws.Rows.Count, "D").End(xlUp).Row), _
                        SortOn:=xlSortOnValues, Order:=xlAscending, DataOption:=xlSortNormal
        .SetRange ws.Range("A3:G" & ws.Cells(ws.Rows.Count, "D").End(xlUp).Row)
        .Header = xlNo
        .Apply
    End With
End Sub