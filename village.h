/*
 COPYRIGHT (C) 2017 Joshua Foss (jmf185) All rights reserved.
 CSI assignment
 Author. Joshua Foss
 jmf185@zips.uakron.edu
 Version. 1.01 07.09.2017
 Purpose:
*/#ifndef VILLAGE_H
#define VILLAGE_H


class village
{
    public:
        /** Default constructor */
        village(int size);

        /** Access size
         * \return The current value of size
         */
        int Getsize() { return size; }
        /** Set size
         * \param val New value to set
         */
        void Setsize(int val) { size = val; }

    protected:

    private:
        int size; //!< Member variable "size"
};

#endif // VILLAGE_H
