// 600fed38  FUN_600fed38  size=102 bytes
// --- callers ---
// --- callees ---
//   6009506c FUN_6009506c


void FUN_600fed38(undefined2 param_1,undefined1 param_2)

{
  undefined2 local_2bc;
  undefined1 local_2ba;
  int local_c;
  
  local_c = FUN_6009506c(param_1);
  if ((local_c != 0) && (**(int **)(local_c + 0xc) != 0)) {
    local_2bc = param_1;
    local_2ba = param_2;
    (*(code *)**(undefined4 **)(local_c + 0xc))(0x12,&local_2bc);
  }
  return;
}


