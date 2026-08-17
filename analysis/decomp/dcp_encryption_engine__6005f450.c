// 6005f450  dcp_encryption_engine__6005f450  size=218 bytes
// src: dcp_encryption_engine.cc
// --- callers ---
//   600e70ba FUN_600e70ba
// --- callees ---
//   6005f418 dcp_encryption_engine__6005f418
//   60101b76 FUN_60101b76
//   6005f310 FUN_6005f310
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   601016f0 FUN_601016f0
//   60051120 FUN_60051120
//   6013d008 thunk_EXT_FUN_00001d6c
//   6013d250 thunk_EXT_FUN_00001d44
//   6013cf30 thunk_EXT_FUN_00001c30
//   6013cf40 thunk_EXT_FUN_00007d10
//   6013cfa8 thunk_EXT_FUN_00001e10


/* src: dcp_encryption_engine.cc */

char dcp_encryption_engine__6005f450
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,uint param_7)

{
  char cVar1;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 uStack_c0;
  undefined1 auStack_bc [144];
  char local_2c;
  
  if (((2 < param_7) || (*(int *)(param_6 + 8) != 0x10)) &&
     (cVar1 = dcp_encryption_engine__6005f418(), cVar1 != '\0')) {
    FUN_60051120(&local_c4,DAT_6005f52c,0x12a);
    FUN_60101b76(auStack_bc,DAT_6005f530);
    FUN_601016f0(0x28,local_c4,uStack_c0,auStack_bc);
    return local_2c;
  }
  thunk_EXT_FUN_0000b4c2(param_1 + 4);
  if (*(char *)(param_1 + 0x58) == '\0') {
    cVar1 = '\t';
  }
  else {
    cVar1 = thunk_EXT_FUN_00001c30(param_6,&local_c4,param_1 + 0x5c);
    if (cVar1 == '\0') {
      local_c8 = 1;
      if (param_7 == 1) {
        cVar1 = FUN_6005f310(&local_c8,&local_c4,param_2,param_3,param_4,param_5);
      }
      else if (param_7 == 2) {
        cVar1 = thunk_EXT_FUN_00001e10(&local_c4,param_2,param_3,param_4,param_5);
      }
      else {
        if (param_7 != 0) {
          cVar1 = '\f';
          thunk_EXT_FUN_00001d44(&local_c8);
          goto LAB_6005f4f0;
        }
        cVar1 = thunk_EXT_FUN_00001d6c(&local_c8,&local_c4,param_2,param_3,param_4);
      }
      thunk_EXT_FUN_00001d44(&local_c8);
    }
  }
LAB_6005f4f0:
  thunk_EXT_FUN_00007d10(param_1 + 4);
  return cVar1;
}


