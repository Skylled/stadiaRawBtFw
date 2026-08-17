// 600c7eb8  FUN_600c7eb8  size=156 bytes
// --- callers ---
//   600f37d2 FUN_600f37d2
//   600f6be6 FUN_600f6be6
//   600f367e FUN_600f367e
//   600f622a FUN_600f622a
//   600ae7f8 FUN_600ae7f8
// --- callees ---
//   600c7d64 FUN_600c7d64
//   600c7878 FUN_600c7878
//   600c7960 FUN_600c7960
//   600c7d14 FUN_600c7d14
//   600c78e8 FUN_600c78e8


undefined4 FUN_600c7eb8(int param_1,undefined1 param_2,undefined2 *param_3)

{
  undefined2 local_16;
  undefined4 local_14;
  
  local_14 = 0;
  local_16 = 0;
  switch(param_2) {
  case 1:
    local_14 = FUN_600c7960(*(undefined1 *)(param_3 + 1),*param_3,*(undefined1 *)((int)param_3 + 3))
    ;
    break;
  case 3:
    local_14 = FUN_600c7878(param_2,*param_3);
    break;
  case 0xd:
  case 0x17:
    local_16 = param_3[2];
  case 9:
  case 0xb:
  case 0x1b:
  case 0x1d:
    local_14 = FUN_600c7d64(*(undefined2 *)(param_1 + 0x1a),param_2,param_3[1],local_16,param_3[3],
                            (int)param_3 + 9);
    break;
  case 0x13:
    local_14 = FUN_600c7d14(param_2);
    break;
  case 0x19:
    local_14 = FUN_600c78e8(param_2,0);
  }
  return local_14;
}


