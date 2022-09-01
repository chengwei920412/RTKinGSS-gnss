
#ifndef STRUCTDEF_H
#define STRUCTDEF_H
#include "rtk/rtk.h"

//#define TRANCE_SIMULATION
#define POST_DIM 240000   //ƽ������ά��
#define STS24		21		//INS/GPS״̬ά��
#define WAT3		3		//����ά��
#define DataLength 36000
#define TEN_MINI   600

//���ͬ��ʱ�����
#define T_990MS  (int(0.99*TM_COUNT))
#define T_1010MS (int(1.01*TM_COUNT))
#define T_1100MS (int(1.1*TM_COUNT))

//PPS������Ϊ4����,������
#define PPS_DT 4

#define GPS_MAXTIME 30		//����30��δУ���˳�״̬

#define DZS_GPS_MAXTIME 6		//����30��δУ���˳�״̬

//�������
//#define PI			3.14159265358979		//Բ����
#define Rad_Deg		57.29577951308232		//���Ȼ�Ϊ�ȵĿ̶�ϵ�� 180./PI
#define Deg_Rad		0.0174532925199433		//�Ȼ�Ϊ���ȵĿ̶�ϵ�� PI/180.
#define Min_Rad		2.908882086657216e-4	//�Ƿֻ�Ϊ����
#define Dph_Rps		4.8481368110953599e-6	//��/Сʱ��Ϊrad/s

#define Rp			6356752.				//����̰���, ��λ����
#define e			0.00335281093			//������Բ�� 1/298.2572 
#define Wie			7.2921151467e-5     	//������ת������, ��λ������/s
#define KM			1000.					//����
#define Knot_Ms 	0.5144444444			//�ڻ�Ϊm/s��ϵ�� 1852./3600.0	
#define mg        	9.80154454e-3			//mg
#define g0        	9.80154454				//g0
#define PPM        	1.0e-6					//ppm

#define GYRO_TAO  	3600.					//����ʱ�䳣��



//����ʱ��궨��
#define SWAY_MIN		1				//�ֶ�׼ʱ��(min)
#define START_INS_TIME      60
#define CALIGN_TIME 	60				//�ֶ�׼ʱ��(s)
#define ALIGN_TIME    	300				//�ܶ�׼ʱ������(s)
#define ENOUGH_ALIGN_TIME    	150				//�ܶ�׼ʱ������(s)

#define TM_STEP	 		0.0025			//��������(s)
#define TM_COUNT 		400				//����Ƶ��(Hz)
#define TF 		  	 	0.1				//KF״̬ת������
#define SmoothCount   2


#define DZS_TM_COUNT 		200				//����Ƶ��(Hz)
#define GPS_TM_COUNT 		40				//����Ƶ��(Hz)
#define DZS_TM_STEP	 		0.005			//��������(s)
#define SQRT_DZS_TM_STEP    sqrt(0.005)
//#define FEEDBACK_TIMES_STEP      5*DZS_TM_STEP


//���ͬ��ʱ�����
#define DZS_T_190MS  (int(GPS_TM_COUNT-2))
#define DZS_T_210MS (int(GPS_TM_COUNT+2))
#define DZS_T_230MS (int(GPS_TM_COUNT+6))
#define DZS_T_990MS  (int(0.99*DZS_TM_COUNT))
#define DZS_T_1010MS (int(1.01*DZS_TM_COUNT))
#define DZS_T_1100MS (int(1.1*DZS_TM_COUNT))

#define T_990MS  (int(0.99*TM_COUNT))
#define T_1010MS (int(1.01*TM_COUNT))
#define T_1100MS (int(1.1*TM_COUNT))


//���ļ���
//#define FILE_NUM  10
#define FILE_NUM  11
#define FILE_NUM_RAW  2
#define PARA_FILE_NAME  "ϵͳ������.txt"
#define GPS_FILE_NAME   "GPS_B.txt"
#define PPGPS_FILE_NAME "PP_Data.dat"
#define IMU_FILE_NAME   "IMU_DECODEFILE.txt"

#define OUT_GPS_NAME   "Gps.txt"
#define OUT_IMU_NAME   "ImuGps.txt"

#define OUT_NAV_NAME   "Navi.txt"
#define OUT_NAV_NAME_5MS   "Navi_5MS.txt"
#define OUT_NAV_NAME_Event   "Navi_Event.txt"
#define OUT_NAV_VM_5MS  "Navi_5MS_VM.txt"


#define VMDIM 9
#define Re			6378137.				//���򳤰���, ��λ����

//����1
//#define RVMP   0.002*0.002/Re/Re
//#define RVMH   0.005*0.005
//#define RVMV   0.0001*0.0001   
//#define RVMA   0.0001*0.0001

#define RVMP   0.02*0.02/Re/Re
#define RVMH   0.05*0.05
#define RVMV   0.001*0.001   
#define RVMA   0.001*0.001
//������ṹ��
typedef struct
{
	double	Kg[3];
	double	Ka[3];
	double	G0[3];
	double	A0[3];

	double	Dg[3][3];
	double	Da[3][3];

	double	Rx[3];
	double	Ry[3];
	double	Rz[3];
}PARA_STRUCT;

//������IMU_GPS����
typedef struct 
{
	unsigned int	Count;
	double	Wm[3];
	double	Vm[3];
	unsigned char   PPS_Flag;
	double	Delay;
	unsigned char    Valid1;
	double	GpsPos1[3];
	unsigned char    Valid2;
	double	GpsPos2[3];
	int     Temp_d;
	double  Temp_f;//IMU time
	double	Sec1;
	double	Sec2;

}IMU_GPS;

typedef struct  
{
	int   LOST_Flag;
	double  GPSLOSTTime;
	double  GPSCalTime;
}GPS_LOST_CLOCK;

/*9άfpr�˲���*/


typedef struct 				//������ز�������
{
	double 	Rs;				//sinL
	double 	Rc;				//cosL
	
	double	Rmh;			//����Ȧ���ʰ뾶
	double	Rnh;			//î��Ȧ���ʰ뾶

	double 	g;				//�������ٶ�
	double 	Wz;				//Wie�������
	double	Wn;				//Wie�������
	double	Wen_n[3];		//Wen��nϵͶӰ
	double	Win_n[3];		//Win��nϵͶӰ
	double 	Win_b[3];		//Win��bϵͶӰ
	double	A_Cori[3];		//���ϼ��ٶ�

	double	A_Cori_XYZ[3];		//���ϼ��ٶ�
	double  g_XYZ[3];//�������ٶ�
	double Wie_b[3];//Wie��bϵͶӰ

}EARTH_DATA;

/********** ����������������ṹ�� **********/
typedef struct
{
	unsigned char	WorkSts;		//����״̬(0-Ĭ��; 1-�ֶ�׼; 2-����׼; 3-����; 4-GPS���; 5-RTKGPS���)
	unsigned char	Align_Fault;	//��׼����(0-Ĭ��; 1-����)
	
	unsigned char	T5MS_Flag;		//5mS��־
	unsigned char	T1S_Flag;		//1S��־
	unsigned char	T10S_Flag;		//10S��־
	
	////

	unsigned char	T200MS_Flag;		//1S��־
	////
	unsigned char   UPDATE_KF_FLAG;   //���¿������˲���־
	
	double 			Att[3];			//��̬��:  ����/���/����(rad)
	double 			Vg[3];			//�ٶ�:    Ve/Vn/Vu(m/s)
	double			Pos[3];			//λ��:    ����(rad)/γ��/(rad)��/(m)

	double          PoseBLH[3];
	double          PosXYZ[3];
	double          AttXYZ[3];
	double 			VXYZ[3];			//�ٶ�:    ecef,x,y,z

	
	double			Rb[3];			//�˱�:    ��ǰ��(m)
	double			Rms[4];			//����:    ��̬(��)/����(��)/�ٶ�(m/s)/λ��(m)
	
	unsigned int	Align_Time;		//��׼ʱ��(s)
	unsigned int	Navi_Time;		//����ʱ��(s)
	
	unsigned int	Inte_Time;		//��ϴ���(s)
	unsigned int	X2Over_Time;	//X2���鳬�����(s)
	unsigned char	FinishAlignFlag;//��׼������־

}NAVI_OUTPUT;
typedef struct
{
	double          timef;          //UTCʱ��
	double 			Att[3];			//��̬��:  ����/���/����(rad)
	double 			Vg[3];			//�ٶ�:    Ve/Vn/Vu(m/s)
	double			Pos[3];			//λ��:    ����(rad)/γ��/(rad)��/(m)
}POS_OUT_DATA;

/********** ���ζ��ֶ�׼�ṹ�� **********/
typedef struct
{	
	unsigned int    pRead;
	unsigned int    pStore;	
	double 			Q_ib0[4];
	double 			Cb_ib0[3][3];
	double 			VGi0[3];
	double 			Sum_VGi0[3];
	double 			VFib0[3];
	double 			Sum_VFib0[3];
	double 			VGi0_S[SWAY_MIN][3];
	double 			VFib0_S[SWAY_MIN][3];
	double          Aligntime;
}CALIGN_DATA;

typedef struct
{
	double 			Q_ib0[4];
	double 			Cb_ib0[3][3];
	double 			Att[3];			//��̬��:  ����/���/����(rad)
	int movecount;
	int continuousmovecount;
	int basesta;
	double LastGpsPos[3];
	double GpsPos[3];
}ONESECOND_ALIGN_DATA;

/********** ��С���˾���׼�ṹ�� **********/
typedef struct
{	
	double Theta_gb_z;

    int    Tk;
    double delta_wz;
    double ae;
    double be;
    double an;
    double bn;
    double fe;
    double fn;
    
    double Align_W0[3];
	double Align_A0[3];
}FALIGN_DATA;
	
/********** ��������ṹ�� **********/
typedef struct
{
	unsigned long	TimeCount;		//����ʱ�����
	unsigned char	T100MS_Flag;		//100MS��־
	unsigned char	T30S_Flag;			//30S��־
	unsigned char	T60S_Flag;			//30S��־

	double			Q[4];				//��Ԫ��
	double			Cb_n[3][3];			//��̬ת������

	double         Qb_e[4];//��Ԫ��
	double         Cb_e[3][3];//��̬ת������
	double         Cn_e[3][3];//��̬ת������

	double			Kg[3];				//

	double			SumFb[3];			//�ӼƱ����ۻ�
	double			SumWb[3];			//�ӼƱ����ۻ�
	double			SumFai[3];			//ƽ̨������

	double			ThetaA1[3];			//�����������
	double			DeltaV1[3];			//�������ٶ�����
	double			Last_DTh[3];		//�����ڽ�����

	NAVI_OUTPUT		OutData;			//�������	

	//����У��ʹ�ñ���
	double			Xk[STS24];			//״̬����ֵ
	double			Pk[STS24][STS24];	//״̬���Ʒ�����
	double			Qt[STS24];			//״̬����������
    double          FeedBack[STS24];
	double          Kk[STS24][WAT3];
	double			Fk[STS24][STS24];	//״̬ת�ƾ���

	double			H[WAT3][STS24];		//����������
	double			R[WAT3][WAT3];		//������������	
	double			Z[WAT3];			//����ֵ

	double 			Zero_W0[3];			//������λ��ϲ�����
	double 			Zero_A0[3];			//�Ӽ���λ��ϲ�����

	unsigned int	TransCount;			//ʱ����´���
	unsigned int	TransFlag;			//����һ��Ԥ��
	unsigned int	NoFilterTime;		//δ�˲�ʱ��
	unsigned int	FilterCount;		//�˲�����
	unsigned char	MesFlag;			//�˲������־

	double preuptime;//0712
	int GPS_FILE_TM_COUNT;
	double FEEDBACK_TIMES_STEP;
	double VectorforGN[5];
	double tempQ0[4],tempQ1[4];
	double Navqpvbeween[10];
	int lastupdatecount;
	int Initial_GN;
	double Temp_f;
	int  screencount;
	int  graphitercount;
}NAVIGATION_DATA;


/********** INS/GPS���ʱ��ṹ�� **********/
typedef struct
{
    unsigned int	T990ms;
    unsigned int	T1010ms;
    unsigned int	T1100ms;

	double			InsPos[3][3];
	double			LockPos[3];

	unsigned char	SyncStatus;
	unsigned char	GpsMode;			//(0-GPS; 1-RTK_GPS)
}INS_GPS_SYNC;
/********** INS/GPS���ʱ��ṹ�� **********/
typedef struct
{
	unsigned int	T190ms;
	unsigned int	T210ms;
	unsigned int	T230ms;

	double			InsPos[3][3];
	double			LockPos[3];

	unsigned char	SyncStatus;
	unsigned char	GpsMode;			//(0-GPS; 1-RTK_GPS)
}DZS_INS_GPS_SYNC;


typedef struct
{
    double Ka[3];			//�Ӽƿ̶����ӣ�  0:x��1:y��2:z
    double Ka_z[3];		//�Ӽ����̶����ӣ�0:x��1:y��2:z
    double Ka_f[3];		//�ӼƸ��̶����ӣ�0:x��1:y��2:z
    double a0[3];			//�Ӽ���λ

    double Kg[3];			//���ݿ̶����ӣ�0:x��1:y��2:z
    double Kg_z[3];		//�������̶����ӣ�0:x��1:y��2:z
    double Kg_f[3];		//���ݸ��̶����ӣ�0:x��1:y��2:z
    double w0[3];			//������λ

	double Bal1[6];

	double Lim_l;     //�ӹߵ�����������ĵĸ˱� 168
	double Lim_b[3];
	double Lim_t[3];
	double Lim_G;    //Gps����ӹߵ��������ĵĸ˱�169

	double GDalfa_XZ  ;   
	double GDalfa_XY  ;
	double GDalfa_YZ  ;
	double GDalfa_YX  ;
	double GDalfa_ZX  ;   
	double GDalfa_ZY  ;

	double ADalfa_XZ  ;   
	double ADalfa_XY  ;
  
	double ADalfa_YZ  ;
	double ADalfa_YX  ;
  
	double ADalfa_ZX  ;    
	double ADalfa_ZY  ;
	double TempeRate_Gyrox[6];	//x������λ�仯���¶�б�ʲ���27~32
	double	TempeRate_Gyroy[6];	//y������λ�仯���¶�б�ʲ���33~38
	double	TempeRate_Gyroz[6];	//z������λ�仯���¶�б�ʲ���39~44

	double Lim_b_accx[3]; //	    �ӱ����ĸ˱�X  176~178
	double Lim_b_accy[3]; //		�ӱ����ĸ˱�Y  179~181
	double Lim_b_accz[3]; //		�ӱ����ĸ˱�Z  182~184
}PARA_DATA;



typedef struct
{
	double Wm0[POST_DIM];
	double Wm1[POST_DIM];
    double Wm2[POST_DIM];

	double Vm0[POST_DIM];
    double Vm1[POST_DIM];
	double Vm2[POST_DIM];

	double GpsPos2_0[POST_DIM];
	double GpsPos2_1[POST_DIM];
	double GpsPos2_2[POST_DIM];

	double Delay[POST_DIM];
	unsigned char Valid[POST_DIM];
	unsigned char PPS_Flag[POST_DIM];
	int FWorkStatus[DataLength];
	int Fintetime[DataLength];
	int BWorkStatus[DataLength];
	int Bintetime[DataLength];
	int gpsvali[DataLength];

	double Fatti0[DataLength];
	double Fatti1[DataLength];
	double Fatti2[DataLength];
	double Fv0[DataLength];
	double Fv1[DataLength];
	double Fv2[DataLength];
	double Fpos0[DataLength];
	double Fpos1[DataLength];
	double Fpos2[DataLength];
	double Fkg0[DataLength];
	double Fkg1[DataLength];
	double Fkg2[DataLength];
	double FZeroW00[DataLength];
	double FZeroW01[DataLength];
	double FZeroW02[DataLength];
	double FZeroA00[DataLength];
    double FZeroA01[DataLength];
    double FZeroA02[DataLength];
	double FRb0[DataLength];
    double FRb1[DataLength];
    double FRb2[DataLength];
	double FTemp_f[DataLength];

	double Batti0[DataLength];
	double Batti1[DataLength];
	double Batti2[DataLength];
	double Bv0[DataLength];
	double Bv1[DataLength];
	double Bv2[DataLength];
	double Bpos0[DataLength];
	double Bpos1[DataLength];
	double Bpos2[DataLength];
	double Bkg0[DataLength];
	double Bkg1[DataLength];
	double Bkg2[DataLength];
	double BZeroW00[DataLength];
	double BZeroW01[DataLength];
	double BZeroW02[DataLength];
	double BZeroA00[DataLength];
    double BZeroA01[DataLength];
    double BZeroA02[DataLength];
	double BRb0[DataLength];
    double BRb1[DataLength];
    double BRb2[DataLength];
	double BTemp_f[DataLength];

	int FNavCount[DataLength];
	int BNavCount[DataLength];

	double FAttiRms[DataLength];
	double FHdgRms[DataLength];
	double FVeRms[DataLength];
	double FPosRms[DataLength];

	double BAttiRms[DataLength];
	double BHdgRms[DataLength];
	double BVeRms[DataLength];
	double BPosRms[DataLength];


	int flighttime;	
	int sflighttime;
	int StoreIndex;

	int CalIndex;
	int ControlCount;

	int PBufferLength;

	int ForWardIndex;
	int BackWardIndex;

}POST_DATA;



/********** ����������������ṹ�� **********/
typedef struct
{
	double			DTheta0[3];		//XYZ�������(rad)	
	double			DeltaV0[3];		//XYZ���ٶ�����(m/s)
	
	unsigned char	PPS_Flag;		//PPS��־(1-��Ч; 0-��Ч,�ⲿ���)
	double			Delay;			//PPS�ӳ�ʱ��
	unsigned char   GpsValid;		//GPSλ����Ч��־(0-��Ч; 1-GPS; 2-GPSRTK)
	double			GpsPos[3];		//GPS��γ��(rad/rad/m)
	double			GpsPosXYZ[3];	//ecef����ϵ
	unsigned char	InteCmd;		//�ⲿ���ָ��(0-����, 1-GPS���)
}NAVI_INPUT;


typedef struct _tagNAV_DATA
{
	double time;
	double latitude;
	double longitude;
	double altitude;
	double x_velocity;
	double y_velocity;
	double z_velocity;
	double roll;
	double pitch;
	double platform_heading;
	double wander_angle;
	double x_accleration;
	double y_accleration;
	double z_accleration;
	double x_angular_rate;
	double y_angular_rate;
	double z_angular_rate;
} POSOUT_NAV_DATA;
//#define TIME_LBounD 70e4
#define TIME_LBounD 6.0e4
#define TIME_BounD  130e8

#define SEG_SUCCESS 1;
#define SEG_ERROR_IN_THE_BEGIN_OF_DATA 97;
#define SEG_ERROR_IN_THE_MID_OF_DATA 98;
#define SEG_ERROR_IN_THE_END_OF_DATA 99;

#define PHASE_TIME_DIS 50
#define PHASE_DIS  600

typedef struct {
	int time;
	double data;
	int seconds_after_last_point;
	int seconds_between_bad_points_before;
	int seconds_between_bad_points_after;
}TIME_POINTS;

typedef struct
{
	double Kg[3];
	double Zero_W0[3];
	double Zero_A0[3];
	double Rb[3];

}KF_FEED_VAR;



#endif