// 6006a5c8  gatt_server__6006a5c8  size=98 bytes
// src: gatt_server.cc
// --- callers ---
//   600d89ec adapter__600d89ec
//   6006a944 gatt_server__6006a944
//   60068f88 activation_sequence__60068f88
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   600d37ac FUN_600d37ac
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60101740 FUN_60101740


/* src: gatt_server.cc */

undefined2 * gatt_server__6006a5c8(undefined2 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 auStack_a0 [144];
  
  thunk_EXT_FUN_0000b5ba(param_1,0,0x14);
  if (*param_2 == 0) {
    *param_1 = 2;
    param_1[2] = (short)param_2[1];
  }
  else {
    if (*param_2 != 1) {
      local_a8 = DAT_6006a62c;
      local_a4 = 0x13;
      FUN_600d3b3a(auStack_a0);
      FUN_600d37ac(auStack_a0,DAT_6006a630);
      FUN_60101740(&local_a8);
    }
    piVar2 = (int *)(param_1 + 2);
    *param_1 = 0x10;
    piVar3 = param_2 + 1;
    do {
      piVar4 = piVar3 + 2;
      iVar1 = piVar3[1];
      *piVar2 = *piVar3;
      piVar2[1] = iVar1;
      piVar2 = piVar2 + 2;
      piVar3 = piVar4;
    } while (piVar4 != param_2 + 5);
  }
  return param_1;
}


