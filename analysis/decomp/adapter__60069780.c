// 60069780  adapter__60069780  size=256 bytes
// src: adapter.cc
// --- callers ---
//   60081234 advertiser__60081234
// --- callees ---
//   60092edc FUN_60092edc
//   600b0974 FUN_600b0974
//   6010165c FUN_6010165c
//   6013cf40 thunk_EXT_FUN_00007d10
//   600d8994 FUN_600d8994
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600d89ec adapter__600d89ec
//   600d8a12 FUN_600d8a12
//   6009cc7c FUN_6009cc7c


/* src: adapter.cc */

uint adapter__60069780(int param_1,int param_2,undefined4 param_3,undefined4 param_4,short param_5,
                      short param_6,char param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else {
    thunk_EXT_FUN_0000b4c2(param_1 + 0x1ed4);
    *(char *)(param_1 + 0x1f2f) = param_7;
    if (*(char *)(param_1 + 0x1f28) != '\0') {
      local_30 = *(undefined1 *)(param_1 + 0x1f2e);
      local_2f = *(undefined1 *)(param_1 + 0x1f2d);
      local_2e = *(undefined1 *)(param_1 + 0x1f2c);
      local_2d = *(undefined1 *)(param_1 + 0x1f2b);
      local_2c = *(undefined1 *)(param_1 + 0x1f2a);
      local_2b = *(undefined1 *)(param_1 + 0x1f29);
      iVar1 = FUN_600b0974(&local_30);
      if (iVar1 == 0) {
        FUN_6010165c(0x28,PTR_s_adapter_cc_60069884,0x27f,
                     PTR_s_Failed_to_set_random_BD_address_a_60069880);
      }
    }
    thunk_EXT_FUN_00007d10(param_1 + 0x1ed4);
    if (param_5 == 0) {
      param_5 = 0x20;
    }
    if (param_6 == 0) {
      param_6 = 0x20;
    }
    iVar1 = FUN_6009cc7c(param_5,param_6,0,7);
    if (iVar1 != 0) {
      FUN_6010165c(0x1e,PTR_s_adapter_cc_60069884,0x296,
                   PTR_s_Failed_to_set_advertising_speed_p_60069888,iVar1);
    }
    uVar2 = adapter__600d89ec(param_1,param_3,0);
    if (((uVar2 & 0xff) == 0) && (uVar2 = FUN_600d8a12(param_1,param_4), (uVar2 & 0xff) == 0)) {
      if (param_7 == '\x01') {
        uVar3 = 0x200;
      }
      else {
        uVar3 = 0x100;
      }
      FUN_60092edc(uVar3,0x100,param_2 == 1,0xff);
      uVar2 = 0;
    }
  }
  return uVar2;
}


