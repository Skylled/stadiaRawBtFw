// 600d8ac6  FUN_600d8ac6  size=34 bytes
// --- callers ---
//   6006ad00 gatt_server__6006ad00
//   6006ae20 gatt_server__6006ae20
//   6006ab14 gatt_server__6006ab14
//   6006a9c8 gatt_server__6006a9c8
// --- callees ---
//   60050c18 FUN_60050c18
//   60101ba2 FUN_60101ba2


int * FUN_600d8ac6(int *param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60050c18(param_2,0,param_1[2] + *param_1,param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


