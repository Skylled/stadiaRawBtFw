// 600d8bea  FUN_600d8bea  size=32 bytes
// --- callers ---
//   6006ad00 gatt_server__6006ad00
//   6006a944 gatt_server__6006a944
//   6006a880 gatt_server__6006a880
//   6006ae20 gatt_server__6006ae20
//   6006ab14 gatt_server__6006ab14
//   6006a9c8 gatt_server__6006a9c8
// --- callees ---
//   60068e98 FUN_60068e98
//   60101ba2 FUN_60101ba2


int * FUN_600d8bea(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_60068e98(param_2,*param_1 + param_1[2],param_1[1] - param_1[2]);
  FUN_60101ba2(param_1,uVar1);
  return param_1;
}


